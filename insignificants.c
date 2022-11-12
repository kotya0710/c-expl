#define INSIGNIFICANT
int main()
{
	;
	INSIGNIFICANT
	{}
	(void)0;
	// This is ok, no error no pedantic warnings.

	struct { ; }; 		// warning: extra semicolon in struct or union specified [-Wpedantic]
	main((void){}); 	// warning: ISO C forbids empty initializer braces [-Wpedantic]
	0; 			// warning: statement with no effect [-Wunused-variable]
	void; 			// warning: useless type name in empty declaration

	();			// error: expected expression before `)`
	(void); 		// error: expected expression before `;`
	void a;			// error: variable of field declared void
	int b = (void)0;	// error: void value not ignored as it ought to be

	return 0;
}
