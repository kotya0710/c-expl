#include <stdio.h>

struct a; // where is no sence

struct b
{
	struct a a;
};

struct a
{
	int a;
	struct b b;
};

int main()
{
	struct a a;
	a = (struct a){ .a = 1, .b = (struct b){ .a = a } };
	printf("%i %i\n", a.a, a.b.a.a);
	return 0;
}
