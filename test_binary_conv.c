#include "main.h"
#include <stdio.h>
#include <limits.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len1;

	len1 = _printf("%b\n", 32);
	printf("%d\n", len1);
	return (0);
}
