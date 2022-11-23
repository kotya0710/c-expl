#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int word_t;
#define word_fmt "%8x"
#define INF 140

void dump(word_t *a, const int al, const int rowsnum)
{
	const int rows = 4;
	printf("dump ");
	int flag = 0;
	word_t *start = a;
	for(int i=0; i<INF; ++i)
	{
		if(i % rows == 0)
		{
			if(flag)
			{
				printf("\n");
				return;
			}
			if(i / rows >= rowsnum)
			{
				printf("\n...");
				if(al > 0)
				{
					flag = 1;
					a = start + al - rows;
				}
				else
				{
					printf("and so on\n");
					return;
				}
			}
			{
				printf("\n[%p] ", (void *)a);
			}
		}
		printf(word_fmt" ", *(word_t *)a);
		//a += sizeof(word_t); // void * cannot be used in arithmetic (sic!)
		word_t *p = a;
		p += 1;
		a = p;
	}
	//printf(".. and so on\n");
}

#define ROWSNUM 10

const struct { const word_t a; const char *const b; } Alefba[] = {
	{ 0x4, "h" },
	{ 0xe, "e" },
	{ 0x1, "l" },
	{ 0x0, "o" },
	{ 0x8, "w" },
	{ 0x7, "r" },
	{ 0x6, "d" },
};

int main(int argn, char **args)
{
	int selfl = 1;
	word_t *self = calloc(selfl, sizeof(word_t));
	word_t *oldmem = self;
	*(self+0) = 0x4e110;
	*(self+1) = 0x80716; // UNSAFE LOL
	//printf("%ls %ls %ls\n", self, self+1, self+2); // suggested by compiler, prints nothing
	//printf("firstadress %p\n", (void *)(self+0));
	//printf("%i %i %i\n", *(int *)(self+0), *(int *)(self+1), *(int *)(self+2)); // -1 0 0
//	word_t *p = self;
	printf("before program read ");
	dump(self, -1, ROWSNUM);
//	self = p;
	FILE *f = fopen(args[0], "r");
	if(f)
	{
		int c = !EOF;
//		word_t *p = self;
		int i=0; // need because using realloc?
		do
		{
			c = fgetc(f);
			if(i >= selfl)
			{
				selfl += 0x10;
				self = realloc(self, selfl * sizeof(word_t));
			}
			self[i] = c;
			i++;
		}
		while(c != EOF);
		selfl = i;
		self = realloc(self, selfl * sizeof(word_t));
		//printf("lastvalue "word_fmt"\n", self[selfl-1]);
		fclose(f);
	}
	printf("after program read ");
	dump(self, selfl, ROWSNUM);
	printf("memory after program ");
	dump(self + selfl, -1, ROWSNUM);
	printf("old memory ");
	dump(oldmem, -1, ROWSNUM);
//	printf();
	//printf("\n");
	free(self);
	return 0;
}

int main_v1()
{
	int al = 8;
	const char *a = calloc(al, sizeof(char));
	// format string for string with length al
	const char pf[] = "%%%is";
	int pl = 1;
	const char *p = calloc(pl, sizeof(char));
	const int pl_new = sprintf((char *)p, pf, al - 1) + 1;
	if(pl_new > pl)
	{
		pl = pl_new;
		p = realloc((char *)p, pl * sizeof(char));
		sprintf((char *)p, pf, al - 1);
	}
	printf("pl %i p %s\n", pl, p); // done
//	int asl = 1;
//	const char **as = calloc(asl, sizeof(char **));
	while(1)
	{
		printf("? ");
		const int st = scanf(p, a);
		printf("a %s st %i\n", a, st);
		if(strcmp(a, "break") == 0)
			break;
//		const int an = strlen(a);
	}
	printf("terminated\n");
	free((char *)p);
	free((char *)a);
	return 0;
}
