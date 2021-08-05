// передача функции массива структур
#include <stdio.h>
#define FUNDLEN 50
#define N 2

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum4(const struct funds money[], int n);

int funds4(void) {
	struct funds jones[N] = {
		{
			"Garlic-Melon Bank",
			4032.27,
			"Lucky's Saving and Loan",
			8543.94
		},
		{
			"Honest Jack's Bank",
			3620.88,
			"Party Time Saving",
			3802.91
		}
	};
	printf("Total sum on Stan's funds consist of $%.2f.\n",
			sum4(jones, N));
	return 0;
}
/* суммирование двух чисел типа double */
double sum4(const struct funds money[], int n) {
	double total;
	int i;
	
	for(i = 0, total = 0; i < n; i++)
		total += money[i].bankfund + money[i].savefund;
	return total;
}
