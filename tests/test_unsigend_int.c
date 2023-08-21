#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Test passing a character to _printf
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned int ui;
    ui = (unsigned int)INT_MAX + 1024;

    _printf("Unsigned:[%u]\n", ui);

	return (0);
}