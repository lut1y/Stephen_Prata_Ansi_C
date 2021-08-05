#include <stdio.h>

int task2(void) {
	int num, numAdded10;
	
	printf("Enter number: ");
	scanf("%d", &num);
	numAdded10 = num + 10;
	while(num++ <= numAdded10)
		printf("%4d", num-1);
	
	return 0;
}
