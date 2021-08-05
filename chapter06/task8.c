#include <stdio.h>

int task8(void) {
	float a, b;
	
	printf("Enter operand a and b (or 'q' for exit): ");
	while((scanf("%f%f", &a, &b))==2) {
		printf("(a-b)/(a*b) = %.2f\n", (a-b)/(a*b));
		printf("Enter operand a and b (or 'q' for exit): ");
	}
	
	return 0;
}
