#include <stdio.h>
#define NUM_LETTER 21

int task4(void) {
	char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int row, col, num;
	
	for(num=0, row=0; num<NUM_LETTER; row++) {
		for(col=0; col<row+1; col++, num++)
			printf("%c", lets[num]);
		printf("\n");
	}
	
	return 0;
}
