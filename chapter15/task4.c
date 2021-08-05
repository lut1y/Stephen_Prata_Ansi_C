#include <stdio.h>
#include <stdbool.h>

bool statusbit(int number, int position);

int task4(void) {
	int number;
	int position;
	
	printf("Enter number (or 'q' for exit): ");
	while(scanf("%d", &number) == 1) {
		printf("Enter position (or 'n' for next position): ");
		while(scanf("%d", &position) == 1 ||
				position > sizeof(int) ) {			
			printf("In position %d : %c.\n", position,
					(statusbit(number, position) == true) ? '1' : '0');			
			printf("Enter next position (or 'n' for position): ");
		}
		printf("Enter next number (or 'q' for exit): ");
	}
	
	puts("Program is finished.");
	return 0;
}

bool statusbit(int number, int position) {
	int i;
	
	for(i=0; i < position; i++, number >>= 1) ;
	if(01 & number) return true;
	return false;
}
