// новые правила для блоков С99
#include <stdio.h>
// -std=c99, -std=gnu99, -std=c11 or -std=gnu11
int forc99(void) {
	int n = 8;
	
	printf("      Firstly n = %d in address %p\n", n &n);
	/*for(int n=1; n < 3; n++)
		printf("     cycle 1: n = %d in address %p\n", n, &n);
	printf("After cycle 1 n = %d in address %p\n", n, &n);
	for(int n = 1; n < 3; n++) {
		printf("index cycle 2 n = %d in address %p\n", n, &n);
		int n = 6;
		printf("     cycle 2: n = %d in address %p\n", n, &n);
		n++;
	}*/
	printf("After cycle 2 n = %d in address %p\n", n, &n);
	
	return 0;
}
