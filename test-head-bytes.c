#include "head.h"

int main()
{
	struct bytes *b = NULL;

	// TEST bytes_from_file
	{
		FILE *f = fopen("test-head-bytes.c", "rb");
		b = bytes_from_file(f);
		printf("\n");
		for(int i=0; i<b->len; ++i)
			printf("%c", (b->a[i]));
		printf("\n");
	}

	free(b->a);
	free(b);

	return 0;
}
