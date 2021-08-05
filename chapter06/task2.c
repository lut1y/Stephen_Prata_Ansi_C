#include <stdio.h>
#define ROWS 6

int task2(void) {
	
	int row, col;
	
	for(row=0; row<ROWS; row++) {
		for(col=0; col<row+1; col++)
			printf("$");
		printf("\n");
	}
	
	return 0;
}
