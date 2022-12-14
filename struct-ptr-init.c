#include <stdio.h>
#include <stdlib.h>
int main()
{
	struct a { int a; };

	struct a *a = calloc(1, sizeof(struct a));

	*a = (struct a){ .a = 666 };

	printf("%i\n", a->a);

	free(a);

	return 0;
}
