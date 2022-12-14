#include "head.h"
int main()
{
	struct a {
		List(int)
	};

	struct a a = ListNew(int, 0x8), b = ListNew(int, 0x8);

	for(int i=0; i<10; ++i)
	{
		ListNext(a) = i;
	}

	for(int i=0; i<5; ++i)
	{
		ListNext(b) = i+100;
	}

	ListInsert(a, b, 5);

	ListPrintAll(a, "%i");
	ListKill(a);
	ListKill(b);

	printf("\n\n");

	struct string c = string_from_str("let a; a =1;a<<=3 ;");

	string_print(c);
	printf("\n\n");
	printf("\n\n");

	struct strings *cs = strings_explode(&c, " ");

	for(int i=0; i<cs->len; ++i)
	{
		string_print(cs->a[i]);
		printf("\n");
	}
	printf("\n\n");
	printf("\n\n");
	printf("len was %i\n", cs->len);
	printf("!\n");
	strings_isolate(cs, "<<=");
	strings_isolate(cs, "=");

	for(int i=0; i<cs->len; ++i)
	{
		string_print(cs->a[i]);
		printf("\n");
	}

	

	return 0;
}
