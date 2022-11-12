int main()
{
	int a = 0;
	int b = 0;
	(1 ? a : b) = 1; // error: lvalue required as left operand of assigmenet
	return 0;
}
