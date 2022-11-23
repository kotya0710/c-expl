#include <stdio.h>
int main()
{
	int a = 1;
	start:
	;
	// if no `;` then error: a label can only be part of a statement and a declaration is not a statement
	int b = 2;
	const int c = a;
	printf("%i %i %i\n", a, b, c);
	if(a == 1)
	{
		a = 666;
		b = 777; // Will rewritten by initialization like `c`
		goto start;
	}
	return 0;
}
