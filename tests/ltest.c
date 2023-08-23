#include "main.h"
#include <stdio.h>

int main()
{
	int l1, l2, l3, l4;
	l1 = _printf("%6c\n", 'A');
	l2 = printf("%6c\n", 'A');
	l3 = _printf("%.s", "Hi!\n");
	l4 = printf("%.s", "Hi!\n");
	printf("%d\n%d\n%d\n%d\n", l1,l2,l3,l4);

	return (0);
}
