#include <stdio.h>
int main()
{
	#define a

	#ifdef a
		printf("a defined\n");
	#endif

	int b;

	#ifdef b
		printf("b defined\n");
		// cannot check if variable is declared or not
	#endif

	return 0;
}
