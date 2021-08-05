// возводит числа в целые степени
#include <stdio.h>

double pow(double n, int p); // прототип ANSI

int power(void) {
	double x, xpow;
	int exp;
	
	printf("Enter number and positive decimal power,");
	printf("that\nnumber will be exponented. For finished program");
	printf(" press q.\n");
	while(scanf("%lf%d", &x, &exp) == 2) {
		xpow = pow(x, exp); // вызов функции
		printf("%.3g in power %d equals %.5g\n", x, exp, xpow);
		printf("Enter next pair numbers or 'q' for finishing.\n");
	}
	printf("Hopefully, that you appreciated this exercise -- good buy!\n");
	
	return 0;
}

double pow(double n, int p) { // определение функции
	double pow = 1;
	int i;
	for(i=1; i<=p; i++)
		pow *= n;
	return pow;
}
