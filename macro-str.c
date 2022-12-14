#include <stdio.h>
#include <stdlib.h>

int main()
{
	#define a(b)	\
		#b
	printf("%s\n", a(b));

	#define b(d)	\
		#d[0]
	printf("%c\n", b(c));


	struct lex_command {
		enum {
			lex_command_alias,
			lex_command_exclude,
		} name;
		union {
			struct lex_command_alias { int a; } alias;
			struct lex_command_exclude { int b; } exclude;
		} body;
	} cmd;

	cmd.body.alias.a = 1;

	struct z { int a; int b; } z = { 555, 666 };

	struct x {
		int z;
	} const x = *(const struct x *)&z;

	printf("%i\n", x.z);

	struct aaa {
		int *a;
	} q[] = {
		{ .a = (int[]){ 1, 2, 3, 4, 5, 6 } }, // wow
	};

//	printf("%i\n", q[0].a);

	printf("%i %i %i\n", q[0].a[0], q[0].a[1], q[0].a[2]);
	printf("%li\n", sizeof(q[0].a) / sizeof(q[0].a[0])); // cannot know size

	return 0;
}
