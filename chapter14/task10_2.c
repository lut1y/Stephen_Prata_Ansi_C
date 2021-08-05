#include <stdio.h>
#include <math.h>	// for sqrt()

#define NUM 3
void showmenu10(void);
double twice(double x);
double half(double x);
double thrice(double x);

int task10_2(void) {
	double (*pf[NUM])(double) = {twice, half, thrice, sqrt};
	double val;
	double ans;
	int sel;
	
	printf("Enter a number (negavive to quit): ");
	while(scanf("%lf", &val) && val >= 0) {
		showmenu10();	
		while(scanf("%d", &sel) && sel>=0 && sel <=3) {
			ans = (*pf[sel])(val);
			printf("answer = %f\n", ans);
			ans = pf[sel](val);
			printf("to repeat, answer = %f\n", ans);
			showmenu10();
		}
		printf("Enter next number (negavive to quit):");
	}
	puts("bye");
	return 0;
}

void showmenu10(void) {
	puts("Enter one of the following choices:");
	puts("0) double the value	1) halve the value");
	puts("2) triple the value	3) squareroot the value");
	puts("4) next number");
}

double twice(double x) {return 2.0 * x; }
double half(double x) { return x / 2.0; }
double thrice(double x) { return 3.0 * x; }
