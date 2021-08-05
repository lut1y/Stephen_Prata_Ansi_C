#include <stdio.h>

int main(void) {
	float teaspoon, tablespoon,
		ounce, cup, pint;
	
	printf("Enter volume in cups: ");
	scanf("%f", &cup);
	
	pint = cup / 2;
	ounce = cup * 8;
	tablespoon = ounce * 2;
	teaspoon = tablespoon * 3;
	
	
	printf("%.2f cups is: \n\t%.2f pints\n\t%.2f ounces\n\t%.2f tablespoons\n\t%.2f teaspoons", cup, pint, ounce, tablespoon, teaspoon);
	
}
