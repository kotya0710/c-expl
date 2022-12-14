#include <stdlib.h>
#include <stdio.h>

void f(int *a)
{
	if(!a)
		a=calloc(1, sizeof(int));
	a[0] = 333;
}

int main()
{
	int *a=NULL;
	printf("%p\n", a); // nil
	printf("%i\n", a[0]); // Segmentation fault
	free(a);
	return 0;
}
