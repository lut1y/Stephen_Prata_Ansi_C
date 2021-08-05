#include <stdio.h>
#define SIZE 5

int task14(void) {
	double a[SIZE], b[SIZE];
	double sum = 0.0;
	int i;
	
	printf("Enter %d elements of array:\n", SIZE);
	for(i=0; i<SIZE; i++) {
		scanf("%lf", &a[i]);
		sum += a[i];
		b[i] = sum;
	}
	
	printf("\na: ");
	for(i=0; i<SIZE; i++) printf("%.2lf ", a[i]);
	printf("\nb: ");
	for(i=0; i<SIZE; i++) printf("%.2lf ", b[i]);
	
	return 0;
}
