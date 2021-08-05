#include <stdio.h>

int for_13s(void) {
	int n; // счет с интервалом 13, начиная с 2
	for(n = 2; n < 60; n+=13)
		printf("%d \n", n);
	return 0;
}
