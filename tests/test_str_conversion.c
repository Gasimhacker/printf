#include "main.h"
#include <stdio.h>


/**
 * main - Test passing a character to _printf
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	len1 = _printf("My secret string is %s\n", "ROT13");
	len2 = printf("My secret string is %s\n", "ROT13");
	printf("Length1:[%d], Length2:[%d]\n", len1, len2);

	return (0);
}
