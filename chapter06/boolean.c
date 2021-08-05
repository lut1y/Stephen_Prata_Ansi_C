// использование переменной типа _Bool
#include <stdio.h>

int boolean(void) {
	long num;
	long sum = 0L;
	_Bool input_is_good;
	
	printf("Enter decimal number for subsequent summing: ");
	printf("(or 'q' for finish program): ");
	input_is_good = (scanf("%ld", &num) == 1);
	while(input_is_good) {
		sum += num;
		printf("Enter next decimal number (or 'q' for finish program): ");
		input_is_good = (scanf("%ld", &num) == 1);
	}
	printf("Sum entered numbers equals %ld.\n", sum);
	
	return 0;
}
