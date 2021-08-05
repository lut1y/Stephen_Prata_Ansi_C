#include <stdio.h>
#define SIZE 8

int task13(void) {
	int i, a[SIZE];
	int value = 2; // 2^0
	
	for(i=0; i<SIZE; i++) {
		a[i] = value;
		value *= 2;
	}
	
	for(i=0; i<SIZE; i++) 		
		printf("%4d", i);
	printf("\n");
	i=0;
	do {
		printf("%4d", a[i]);
		i++;
	} while(i<SIZE);	
	return 0;
}
