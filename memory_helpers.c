/**
 * _strlen - Returns the length of the string
 * @s: The string to calculate its length
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*(s + len))
	{
		len++;
	}

	return (len);
}


/**
 * _strcpy - Copy a string in one variable into another variable
 * @src: The string to be copied
 * @dest: The destination of the copied string
 *
 * Return: The pointer to the destination.
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while ((*src) != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (ptr);
}
