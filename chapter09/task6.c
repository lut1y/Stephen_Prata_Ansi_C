#include <stdio.h>

void min_from_3(double *, double *, double *);

int task6(void) {
	double a, b, c;
	
	printf("Enter three values: ");
	while(scanf("%lf %lf %lf", &a, &b, &c) != 3) {
		printf("Error! Enter double number as 2.54 or 7.1E2: ");
		while(getchar() != '\n') continue;
	}	
	printf("Before %g, %g, %g\n", a, b, c);
	min_from_3(&a, &b, &c);
	printf("After %g, %g, %g\n", a, b, c);
	
	return 0;
}

void min_from_3(double *a, double *b, double *c) {
	double temp;
	
	if(*a > *b && *a > *c) { // 5 1 3
		if(*c > *b) {
			temp = *c;
			*c = *a;
			*a = *b;
			*b = temp;
		} else { // 5 3 1
			temp = *c;
			*c = *a;
			*a = temp;
		}
	}
	if(*b > *a && *b > *c) { 
		if(*c < *a) {	// 3 5 1
			temp = *c;
			*c = *b;
			*b = *a;
			*a = temp;
		} else { // 1 5 3 
			temp = *b;
			*b = *c;
			*c = temp;
		}
	}
	if(*a > *b) {
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
