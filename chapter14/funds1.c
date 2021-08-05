// передача членов структуры в качестве аргументов
#include <stdio.h>
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum1(double, double);

int funds1(void) {
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Saving and Loan",
		8543.94
	};
	printf("Total sum on Stan's funds consist of $%.2f.\n",
			sum1(stan.bankfund, stan.savefund));
	return 0;
}
/* суммирование двух чисел типа double */
double sum1(double x, double y) {
	return (x + y);
}
