#include <stdio.h>
#define ROWS 6

int task3(void) {
	char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int row, col;
	
	for(row=0; row<ROWS; row++) {
		for(col=0; col<(row+1); col++)
			printf("%c", lets[ROWS-1-col]);
		printf("\n");
	}
	
	return 0;
}
