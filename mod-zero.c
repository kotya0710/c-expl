#include <stdio.h>

int main()
{
	int a = 5 % 0;// warning: division by zero
	// Floating point exception
	printf("%i\n", a);
	return 0;
}
