#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    void *addr;
    int i;
    addr = (void *)0x7ffe637541f0;

    i = _printf("Address:[%p]\n", addr);

    _putchar(i + '0');

	return (0);
}
