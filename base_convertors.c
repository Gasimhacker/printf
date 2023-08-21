/**
 * to_binary - Convert an unsigned integer to binary
 * @n: The number to be converted
 *
 * Return: A to the binary
 *	   representation (as a string) of the argument passed
 */
char *to_binary(unsigned int n)
{
	int i = 32;
	char ans[33];
	char *ptr = ans;

	ans[32] = '\0';

	while (i && n)
	{
		ans[--i] = (n % 2) + '0';
		n /= 2;
	}

	return (ptr + i);

}
