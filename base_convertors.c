/**
 * to_binary - Convert an unsigned integer to binary
 * @n: The number to be converted
 *
 * Return: The binary representation of the argument passed
 */
unsigned int to_binary(long unsigned int n)
{
	if (n == 1 || n == 0)
		return (n);
	return ((n % 2) + (10 * to_binary(n / 2)));
}
