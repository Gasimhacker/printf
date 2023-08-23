#include "main.h"
#include <stdio.h>

int main()
{
	int l1, l2, l3, l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17,l18;
	l1 = _printf("%.6s\n", "Best School !\n");
	l2 = printf("%.6s\n", "Best School !\n");
	l3 = _printf("%.6s\n", "Hi!\n");
	l4 = printf("%.6s\n", "Hi!\n");
	l5 = printf("%.0s\n", "Hi!\n");
	l6 = printf("%.0s\n", "Hi!\n");
	l7 = printf("%.s\n", "Hi!\n");
	l8 = printf("%.s\n", "Hi!\n");
	l9 = printf("In the middle %.6s of a sentence.\n", "Best!");
	l10 = printf("In the middle %.6s of a sentence.\n", "Best!");
	l11 = printf("%.*s\n", 6, "Best School !\n");
	l12 = printf("%.*s\n", 6, "Best School !\n");
	l13 = printf("%.*s\n", 6, "Hi!\n");
	l14 = printf("%.*s\n", 6, "Hi!\n");
	l15 = printf("%.*s\n", 0, "Hi!\n");
	l16 = printf("%.*s\n", 0, "Hi!\n");
	l17 = printf("In the middle %.*s of a sentence.\n", 6, "Best!");
	l18 = printf("In the middle %.*s of a sentence.\n", 6, "Best!");

	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17,l18);

	return (0);
}
