#define a(a, b) { int b; return a; }
#define c(b, a) { int b; return a; }
void b()
{
	a(, b) // Can ignore arguments of macro
}
void d()
{
	c(d, ) // Cannot ignore comma
}
int main()
{
	b();
	a(0, main)
}
