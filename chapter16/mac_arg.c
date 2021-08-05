// макросы с аргументами
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("Result: %d.\n", X)

int mac_arg(void) {
	int x = 5;
	int z;
	
	printf("x = %d.\n", x);
	z = SQUARE(x);
	printf("Calculating SQUARE(x): ");
	PR(z);
	z = SQUARE(2);
	printf("Calculating SQUARE(2): ");
	PR(z);
	printf("Calculating SQUARE(x+2): ");
	PR(SQUARE(x+2));
	printf("Calculating 100/SQUARE(2): ");
	PR(100/SQUARE(2));
	printf("x = %d.\n", x);
	printf("Calculating SQUARE(++x): ");
	PR(SQUARE(++x));
	printf("After incremention x = %x.\n", x);
	
	return 0;
}
