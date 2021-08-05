#include <stdio.h>
#include <limits.h>

int countswitchedbytes(int number);

int task3(void) {
	int number;
	
	printf("Enter number (or 'q' for exit): ");
	while(scanf("%d", &number) == 1) {
		
		printf("Enter next number (or 'q' for exit): ");
		printf("%d contains %d bytes.\n", number, countswitchedbytes(number));
	}
	
	puts("Program is finished.");
	return 0;
}

int countswitchedbytes(int number) {
	int i, ct;
	int size = sizeof(int);
	
	for(i=0, ct=0; i<size; i++, number>>=1) 
		if(01 & number) ct++;
	
	
	return ct;
}
