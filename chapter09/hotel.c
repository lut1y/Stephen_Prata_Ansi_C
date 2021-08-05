// функции управления отелем
// МОДУЛЬ ФУНКЦИЙ ПОДДЕРЖКИ
#include <stdio.h>
#include "hotel.h"

int menu(void) {
	int code, status;
	
	printf("\n%s%s\n", STARS, STARS);
	printf("Enter number, corresponding to choiced hotel:\n");
	printf("1) Fairfield Arms\t2) Hotel Olympic\n");
	printf("3) Chertworthy Plaza\t4) The Stockton\n");
	printf("5) quit\n");
	printf("%s%s\n", STARS, STARS);
	while((status = scanf("%d", &code)) != 1 || 
			(code < 1 || code > 5)) {
		if(status != 1)
			scanf("%*s");	// отбрасывание нецелочисленного ввода
		printf("Enter integer number from 1 to 5.\n");
	}
	return code;
}

int getnights(void) {
	int nights;
	
	printf("How many days do you swear the number? ");
	while(scanf("%d", &nights) != 1) {
		scanf("%*s"); 	// исключение нецелочисленного ввода
		printf("Enter integer number, as 2.\n");
	}
	return nights;
}

void showprice(double rate, int nights) {
	int n;
	double total = 0.0;
	double factor = 1.0;
	
	for(n=1; n<=nights; n++, factor *= DISCOUNT)
		total += rate * factor;
	printf("Total cost is $%0.2f.\n", total);
}
