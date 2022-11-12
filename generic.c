#include <stdio.h>

int main()
{
	int a;
	printf(	"%s\n",
		_Generic(
			a,
			int: "int",
			default: "unknown"
		)
	);
	// Prints "int"
	return 0;
}
