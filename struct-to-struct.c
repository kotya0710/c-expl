#include <stdio.h>
int main()
{
	struct a { int a; double b; char c; };
	struct b { int n; double m; char k; };
	struct a a = {1, 2.2, '!'};
//	struct b b = (struct b)a; // error: conversion to non-scalar type requested
	struct b *b = (struct b *)&a;
	printf("%i %f %c\n", b->n, b->m, b->k);
	return 0;
}
