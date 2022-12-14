#include <stdio.h>

struct a;
void f(struct a a){}

int main()
{
	struct {
		int a[2];
	} a = { .a={1, 2} };
	printf("%i %i\n", a.a[0], a.a[1]); // 1 2

	struct a {};
	f((struct a){});
	// error: parameter 1 (‘a’) has incomplete type
	// Cannot complete struct a inside scopes.

	return 0;
}
