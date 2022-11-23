//#define tail(f, a, ...) f(__VA_ARGS__)
//#define dgvdsf 1

#include <stdio.h>

#define fmt_type(a) "%%%s",_Generic((a), int: "i", default: "???")

//#define fmt_types(a, ...) #a" <-- %s\n",fmt_type(a)


//#define pmt(...) fmt(fmt_types(__VA_ARGS__), __VA_ARGS__)



int main()
{
	int a = 987;
//	double b = 123.456;
//	char *s = "hello";

//	pmt(a, b, c);

	char s[1000];

	snprintf(s, 1000, fmt_type(a));
	printf(s,a);

	printf("\n");
	return 0;
}



// mehhh
