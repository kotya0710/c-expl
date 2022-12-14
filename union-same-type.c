int main()
{
	union {
		int a;
		int b;
	} a;
	a.a = 1;
	a.b = 2; // can do this !
	return 0;
}
