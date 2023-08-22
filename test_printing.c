#include <stdio.h>
#include "main.h"

int main ()
{
	int len1, len2;

	len1 = printf("% +d\n", 11);
	len2 = _printf("% +d\n", 11);

	printf("%d\n%d\n", len1, len2);

	return (0);
}
