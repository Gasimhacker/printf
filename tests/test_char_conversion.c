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

	len1 = _printf("My secret letter is %c\n", 'A');
	len2 = printf("My secret letter is %c\n", 'A');
	printf("Length1:[%d], Length2:[%d]\n", len1, len2);

	return (0);
}
