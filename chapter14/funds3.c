// передача структуры
#include <stdio.h>
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum3(struct funds); // аргумент является указателем

int funds3(void) {
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Saving and Loan",
		8543.94
	};
	printf("Total sum on Stan's funds consist of $%.2f.\n",
			sum3(stan));
	return 0;
}
/* суммирование двух чисел типа double */
double sum3(struct funds money) {
	return (money.bankfund + money.savefund);
}
