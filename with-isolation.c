#include "head.h"

int main()
{
	const char *const fp = "main.c";
	printf("%s\n", fp);
	printf("------------------------\n");

	FILE *f = fopen(fp, "rb");
	struct bytes *const b = bytes_from_file(f);
	const struct string s = (const struct string){ .s = (char *)b->a, .starts = 0, .ends = b->len-1 };

	string_wipe(&s, "/*", "*/");
	string_wipe(&s, "//", "\n");

	struct strings *ss = strings_explode(&s, " \n\t");

	// note: operators sorted by length

	strings_isolate(ss, "<<=");
	strings_isolate(ss, ">>=");
	strings_isolate(ss, "->");
	strings_isolate(ss, "++");
	strings_isolate(ss, "--");
	strings_isolate(ss, "==");
	strings_isolate(ss, "<=");
	strings_isolate(ss, ">=");
	strings_isolate(ss, "!=");
	strings_isolate(ss, "->");
	strings_isolate(ss, "+=");
	strings_isolate(ss, "-=");
	strings_isolate(ss, "%=");
	strings_isolate(ss, "/=");
	strings_isolate(ss, "*=");
	strings_isolate(ss, "&=");
	strings_isolate(ss, "|=");
	strings_isolate(ss, "~=");
	strings_isolate(ss, "^=");
	strings_isolate(ss, "&&");
	strings_isolate(ss, "||");
	strings_isolate(ss, ">>");
	strings_isolate(ss, "<<");
	{
		const char *const cs = "~!%^&*()+=-\\/.,<>{}[];:'\"";
		for(int i=0; cs[i]; ++i)
			strings_isolate(ss, ctos(cs[i]));
	}

	for(int i=0; i<ss->len; ++i)
	{
		struct string *s = &ss->a[i];
		printf("[%03i] ", i);
		for(int k=s->starts; k<=s->ends; ++k)
		{
			printf("%c", s->s[k]);
		}
		printf("\n");
	}



	free(ss);
	ListKill(*b);
	free(b);

	return 0;
}
