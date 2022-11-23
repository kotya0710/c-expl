#define a 1
#define b a
#undef a
// error: 'a' undeclared

#define c 1
#define d c
// ok

int main()
{
	return 0;
}
