#include <stdio.h>

double power_(double num, int exp);

int task6() {
	int i, start, finish;
	
	printf("Enter start and finish: ");
	scanf("%d%d", &start, &finish);
	
		printf("n    n^2     n^3\n");
	for(i=start; i<=finish; i++) {
		printf("%d  %6.2lf  %6.2lf\n", i, power_(i, 2), power_(i, 3));
	}
	
	return 0;
}

double power_(double num, int exp) {
	int i;
	double pow = 1;
	
	for(i = 1; i <= exp; i++) 
		pow *= num;
	return pow;	
}
