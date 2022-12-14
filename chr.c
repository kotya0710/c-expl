#include <stdio.h>
int main(int n, const char **b)
{
	{
		const char *a = b[n-1];
		for(;*a;++a)
		{
			printf("   %c ", *a);
		}
		printf("\n");
	}
	{
		const char *a = b[n-1];
		for(;*a;++a)
		{
			printf("0x%02x ", *a);
		}
		printf("\n");
	}
	return 0;
}
