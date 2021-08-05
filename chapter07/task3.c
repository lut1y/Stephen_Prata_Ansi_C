#include <stdio.h>
#include <iso646.h>


int task3(void) {
	int ch;
	int even=0,
		odd = 0,
		sum_odd=0,
		sum_even=0;
	
	printf("Enter number from 1 to 9 (0 for exit): ");
	while(scanf("%d", &ch) == 1 and ch !=0 ) {
		if(ch % 2 == 0) {
			even++;
			sum_even += ch;
		} else {
			odd++;
			sum_odd += ch;
		}
		printf("Enter number from 1 to 9 (0 for exit): ");		
	}
	printf("\nCommon even: %d\nAverage even: %.3f\n"
			"\nCommon odd: %d\nAverage odd: %.3f\n",
			even, (float) sum_even/even,
			odd, (float) sum_odd/odd);
	
	return 0;
}
