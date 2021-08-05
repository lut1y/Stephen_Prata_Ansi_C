#include <stdio.h>
double cub(double n);

int task7(void) {
	double number;
	
	printf("Enter number: ");
	scanf("%lf", &number);
	printf("%.3lf^3 = %.6lf\n", number, cub(number));
	
	return 0;
}

double cub(double n) {
	return n*n*n;
}
