#include <stdio.h>

void larger_of(double *, double *);

int task5(void) {
	double a, b;
	
	printf("Enter two values: ");
	while(scanf("%lf %lf", &a, &b) != 2) {
		printf("Error! Enter double number as 2.54 or 7.1E2: ");
		while(getchar() != '\n') continue;
	}
	printf("Before a = %g and b = %g\n", a, b);
	printf("Because %s, then ", 
		(a>b) ? ("a > b") : ( (a==b) ? "a = b" : "a < b" ));
	if(a != b) larger_of(&a, &b);
	printf("a = %g and b = %g\n", a, b);
	
	return 0;
}

void larger_of(double *x, double *y) {
	if(*x > *y) 
		*y=*x; 
	else
		 *x=*y;
	return;
}
