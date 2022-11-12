int main()
{
	int i;
	int *ip = &i;
	const int *cip = &i;
	int const *icp = &i;
	int *const ipc = &i;
	const int *const cipc = &i;
	int const *const icpc = &i;

	const int a;

	*ip = a;
	ip = &a; // warning: assignment discards ‘const’ qualifier from pointer target type
	// Can modify value from pointer, and can change pointer itself.

	*cip = a; // error: assigment of read-only location
	cip = &a;
	// Cannot modify value from pointer, but can change pointer itself.

	*icp = a; // error: assigment of read-only location
	icp = &a;
	// Same.

	*ipc = a;
	ipc = &a; // error: assigment of read-only variable
	// Can modify value from pointer, but cannot change pointer itself.

	*cipc = a; // error: assigment of read-only location
	cipc = &a; // error: assigment of read-only variable
	// Cannot modify value from pointer, and cannot change pointer itself.

	*icpc = a; // error: assigment of read-only location
	icpc = &a; // error: assigment of read-only variable
	// Same.

	return 0;
}
