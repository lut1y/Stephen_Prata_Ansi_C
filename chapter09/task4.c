#include <stdio.h>

double averageGarmonicValue(double, double);

int task4(void) {
	double x1, x2;
	
	printf("Enter two values: ");
	while(scanf("%lf %lf", &x1, &x2) != 2) {
		printf("Error! Enter double number as 2.54 or 7.1E2: ");
		while(getchar() != '\n') continue;
	}
	printf("Average garmonic value of %g and %g is %g", 
		x1, x2, averageGarmonicValue(x1, x2));
	
	return 0;
}

double averageGarmonicValue(double x1, double x2) {
	return 2.0 / (1.0/x1 + 1.0/x2);	
} 
