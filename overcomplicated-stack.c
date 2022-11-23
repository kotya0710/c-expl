#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "head.h"

#define LIST_NEXT(A, T, acc)	\
	if(A.len >= A.cap)	\
		A.a = realloc(A.a, (A.cap += 1) * sizeof(T));	\
	A.a[A.len++]

struct ptrstack {
	LIST(void *)
};

const struct ptrstack ptrstack_init()
{
	size_t acc = 0x10;
	size_t c = acc;
	void **a = calloc(c, sizeof(void *));
	return (const struct ptrstack){ c, a, 0 };
}

/*
void ptrstack_kill(struct ptrstack a)
{
	if(a.a)
		free(a.a);
}
*/

struct ptrstack ptrstack_access()
{
	static struct ptrstack a = ptrstack_init();
	return a;
}

void ptrstack_free()
{
	struct ptrstack ps = ptrstack_access(); // error: element is not constant
	for(int i=0; i<ps.len; ++i)
		ps.a[i].kill(ps.a[i]);
	free(ps.a);
	ps.cap = 0;
	ps.len = 0;
	ps.a = NULL;
}

void ptrstack_careof(void *a)
{
	struct ptrstack ps = ptrstack_access();
	LIST_NEXT(ps, void *, 0x8) = a;
}

////////////////////////////////////////////

struct somestruct {
	int err;
	void (*kill)(void *);
};

void somestruct_kill(void *a)
{
	printf("somestruct killed\n");
}

struct somestruct somestruct_init()
{
	struct somestruct a;
	printf("somestruct inited\n");
	// ...
	a.kill = &somestruct_kill;
	ptrstack_careof((void *)(&a));
	return a;
}

int main()
{
	struct somestruct a = somestruct_init();
	ptrstack_free();
	return 0;
}
