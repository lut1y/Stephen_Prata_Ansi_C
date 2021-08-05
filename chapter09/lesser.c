#include <stdio.h>

int imin(int, int);

int lesser(void) {
	int evil1, evil2;
	printf("Enter two integer number (or 'q' for finishing):\n");
	while(scanf("%d %d", &evil1, &evil2) == 2) {
		printf("Lower from two numbers %d and %d is %d.\n",
			evil1, evil2, imin(evil1, evil2));
		printf("Enter two integer number (or 'q' for finishing):\n");
	}
	printf("Program is finished.\n");
	return 0;
}

int imin(int n, int m) {
	int min;
	if(n < m)
		min = n;
	else
		min = m;
	return min;
}
