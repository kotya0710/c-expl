int *give_me_integer()
{
	int a = 666;
	return &a;
}

void main()
{
	int *a = give_me_integer();
	// error: function returns address of local variable [-Werror=return-local-addr]
}
