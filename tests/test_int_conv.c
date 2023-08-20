#include "main.h"
#include <stdio.h>


/**
 * main - Test passing an integer to _printf
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	len1 = _printf("My age is %d\n", -23);
	len2 = printf("My age is %d\n", -23);
	printf("Length1:[%d], Length2:[%d]\n", len1, len2);

	return (0);
}
