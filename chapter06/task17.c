#include <stdio.h>

int task17() {
	float price = 1000000; 
	int year = 1;
	
	
	while(price > 0) {
		printf("%4d ", year);
		price *= 1.08;
		printf(" %10.2f", price);
		price -= 100000;
		printf(" %10.2f\n", price);
		year++;
	}
	
	return 0;
}
