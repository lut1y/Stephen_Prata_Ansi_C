// подстановка в строке
#include <stdio.h>
#define PSQR(x) printf("Square " #x " eqauals %d.\n", ((x)*(x)))

int subst(void) {
	int y=5;
	
	PSQR(y);
	PSQR(2+4);
	
	return 0;
}
