#include <stdio.h>

double power(double, int);

int task8(void) {
	char ch;
	double a;
	int x;
	
	printf("Enter number and power (or 'q' for finishing): ");
	while(scanf("%lf %d", &a, &x) == 2) {
		printf("%g^%d = %g\n", a, x, power(a, x));
		printf("Enter next number and power (or 'q' for finishing): ");
	}
	
	return 0;
}

double power(double a, int x) {
	double p = 1.0;
	int i;
	
	if(a == 0) {
		if (x== 0)
			printf("0 to 0 undefined\n");
		p = 0.0;
	} else {
		if(x > 0) {
			for(i=1; i<=x; i++)
				p *= a;
		} else if( x == 0) {
			p = 1.0;
		} else {
			p = 1.0 / power(a, -x);
		}
	}
	return p;
}
