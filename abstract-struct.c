#include <stdio.h>

struct a {
	int a;
	int b;
	double c;
};

struct b {
	int a;
	const char c[4];
	double b;
	int d;
};

struct abstract {
	int a;
	char _[4];
	double b;
};

int main()
{
	const struct a a = { 1, 2, 3.3 };
	const struct b b = { 4, "123", 5.5, 7 };
	const struct abstract *abst = (struct abstract *)&a;
	printf("%i %f\n", abst->a, abst->b);
	// In C ( not C++ ) structure's byte-order garanteed to be persistend with the declaration order,
	// 	althrough not for bit-order in bit-fields.
	return 0;
}
