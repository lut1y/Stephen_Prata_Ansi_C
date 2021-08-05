#include <stdio.h>

double rpower(double, int);

int task9(void) {
	char ch;
	double a;
	int x;
	
	printf("Enter number and power (or 'q' for finishing): ");
	while(scanf("%lf %d", &a, &x) == 2) {
		printf("%g^%d = %g\n", a, x, rpower(a, x));
		printf("%g^%d = %g\n", a, x, power(a, x));
		printf("Enter next number and power (or 'q' for finishing): ");
	}
	
	return 0;
}

double rpower(double a, int x) {
	double p = 1.0;
	int i;
	
	if(a == 0) {
		if (x == 0)
			printf("0 to 0 undefined\n");
		p = 0.0;
	} else {
		if(x > 0) {
			p = a * rpower(a, x-1);
		} else if( x == 0) {
			p = 1.0;
		} else {
			p = 1.0 / rpower(a, -x);
		}
	}
	return p;
}
