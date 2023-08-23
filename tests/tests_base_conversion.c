#include "main.h"
#include <stdio.h>

int main()
{
	int len1, len2, len3, len4;

	len1= _printf("%010p\n", 20);
	len2= printf("%010p\n", 20);

	len3= _printf("%010.4p\n", 11);
	len4= printf("%010.4p\n", 11);
	printf("len1 [%d]\nlen2 [%d]\n", len1, len2);

	printf("len3 [%d]\nlen4 [%d]\n", len3, len4);
	return (0);
}
