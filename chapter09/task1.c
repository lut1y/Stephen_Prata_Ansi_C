#include <stdio.h>

double min(double, double);

int task1(void) {
	double x = 10.0,
		y = 8.0;
	
	printf("Between %g and %g lower %g.\n", x, y, min(x, y));	
	
	return 0;
}

double min(double x, double y) {
	return (x > y) ? y : x ;
}
