#include <stdio.h>
#include <stdlib.h>

/* Convention from 21 nov. 2022
 * 1. First 4 bytes of any structure a.k.a 0+[4] is an error code. >=0 is OK.
 * 2. For list-like objects 0+[4] is capacity, 4+[*] is pointer with that capacity, optionally provided length
 *	and size of element (not fixed).
 */

struct bytes {
	int cap;
	char *a;
	int len;
};

struct bytes breadall(FILE *f)
{
	if(!f)
		return (struct bytes){ -1 };
	size_t sacc = 0x10;
	size_t slen = sacc;
	char *s = calloc(slen, sizeof(char));
	size_t si = 0;
	int c = !EOF;
	while(c != EOF)
	{
		if(si >= slen)
			s = realloc(s, (slen += sacc) * sizeof(char));
		s[si++] = (char)(c = fgetc(f));
	}
	return (struct bytes){ slen, s, .len=si };
}

int bwriteall(FILE *f, const struct bytes b)
{
	if(!f)
		return -1;
	for(size_t i=0; i<b.len; ++i)
		fputc(b.a[i], f);
	return 0;
}

int bcontain(const struct bytes a, const struct bytes b)
{
	if(b.len <= 0 || a.len <= 0)
		return -2;
	for(int i=0; i < a.len; )
	{
		int found = 0;
		for(; i<a.len; ++i)
		{
			if(a.a[i] == b.a[0])
			{
				found = 1;
				break;
			}
		}
		if(!found)
			return -1;
		for(int k=0; i+k<a.len && k<b.len; ++k)
		{
			if(a.a[i+k] != b.a[k])
			{
				found = 0;
				i++;
				break;
			}
		}
		if(found)
			return i;
	}
	return -3; // never happen
}

int main(int argc, char **argv)
{
	const char str1[] = "HelloWorld1234";
	const char str2[] = "AbrahamLinkoln";
	const int slen = 8; // gcc divides strings in executable to chunks with length of 8 bytes
	const struct bytes s1 = (struct bytes){ 15, (char *)str1, slen };
	const struct bytes s2 = (struct bytes){ 15, (char *)str2, slen };
	FILE *f = NULL;
	f = fopen(argv[0], "r");
	if(!f)
	{
		printf("Cannot read file\n");
		return 0;
	}
	const struct bytes b = breadall(f);
	if(b.cap < 0)
	{
		printf("Read 0 bytes\n");
		return 0;
	}
	fclose(f);
	const int i1 = bcontain(b, s1);
	const int i2 = bcontain(b, s2);
	if(i1 < 0 || i2 < 0)
	{
		printf("Strings not found: %i %i\n", i1, i2);
	}
	else
	{
		for(int i=0;i<slen;++i)
		{
			b.a[i1 + i] = str2[i];
			b.a[i2 + i] = str1[i];
		}
	}
	f = fopen(str1, "w");
	if(!f)
	{
		printf("Cannot write file\n");
	}
	const int status = bwriteall(f, b);
	if(status != 0)
	{
		printf("Error while writing %i\n", status);
	}
	fclose(f);
	free(b.a);
	printf("%s\n",str1);
	return 0;
}

int indexof(char *a, char *b)
{
	char *sb = b;
	int i = 0;
	while(*a)
	{
		for(b=sb;*a&&*a!=*b;++a,++i);
		for(;*a&&*b&&*a==*b;++a,++b);
		if(!*b)
			return i;
		++i;
	}
	return -1;
}
