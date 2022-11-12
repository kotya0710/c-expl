#include <stdio.h>

#define PRINTNAME printf("entering %s %s %i\n", __FILE__, __func__, __LINE__);

#define return \
	printf("exiting %s\n", __func__); \
	return

int d()
{
	PRINTNAME
	return 0;
}

int c(int c)
{
	PRINTNAME
	return c;
}

int b()
{
	PRINTNAME
	return 0;
}

int a()
{
	PRINTNAME
	b();
	return c(d());
}

// Ok, functions above does print where are they defined, redifinition of return within calling macro at the
// begining can be used to make proper call stack but there is no way to determine where function was actually
// called without "wrapping" function definition like shown below. Btw cannot figure it out all the way (see
// embedded comms.). "Wrapping" must've been opposite of using PRINTNAME and return redifinition tho.

// Each traced function from now must be defined using this macro.
// Arguments:
// type -- function return type
// name -- function name
// ...  -- arguments of function
#define wrap(type, name, ...) \
	/*1. Defines actuall function header*/ \
	type __wrapped__##name ( __VA_ARGS__ );			\
	/*note: what to do with no argument functions? does not like ","*/ \
	/*2. Defines wrapper calling actual function*/ \
	type name( int called_at_line, __VA_ARGS__ )		\
	{							\
		PRINTNAME					\
		printf(#name " called at line %i\n", called_at_line);	\
		printf("parameter a (%i) cannot be used *sad face* so it is hardcoded lol\n", a);\
		return __wrapped__##name( 1 /* here must be __VA_ARGS__ but without types or what */);		\
			/* Also when I trying to provide arguments separ. for def. and call i produce error i*/ \
			/* do not actually understand... */ \
	}							\
	/*3. Defines actual function*/
	type __wrapped__##name(__VA_ARGS__)

// Each wrapped function must be called using this macro.
// Args:
// name -- function name provided to `wrap`
// ...  -- call arguments
#define call(name, ...) name(__LINE__, __VA_ARGS__)

// Defining wrapped function.
// There is the problem №1. Cannot pass arguments as initialization and call function at the same time.
// So *c, *b should've been arguments of `f1` but they are not.
wrap(int, f1, int a)
{
	PRINTNAME
	double cc = 1;
	double *c = &cc;
	const char *b = "-";
	printf("Function called with arguments\n\ta: %i\n\tb: %s\n\tc: %f\n", a, b, *c);
	*c = 555.5;
	return a + 1;
}

int main()
{
	PRINTNAME

	// Simple call trace (ok but no information about where in code function was called)
	a();

	// "Better" call trace
	// Probl.№2: I must use `call` macro wich is odd, definitely whould not use that, should be way to define
	// "call" macro at "wrap" call to use actuall benifits of wrapping.
	int a = call(f1, 777);
	printf("returns: %i\n", a); // Must return 777 but i could not to figure out how to provide argumnets to
	// wrapped functions so return value hardcoded for no reason.

	// Conclusion: *sad face*

	return 0;
}
