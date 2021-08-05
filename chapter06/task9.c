#include <stdio.h>

float calc(float a, float b) {
	return (a-b)/(a*b);
}

int task9(void) {
	float a, b;
	
	printf("Enter operand a and b (or 'q' for exit): ");
	while((scanf("%f%f", &a, &b))==2) {
		printf("(a-b)/(a*b) = %.2f\n", calc(a, b));
		printf("Enter operand a and b (or 'q' for exit): ");
	}
	
	return 0;
}
