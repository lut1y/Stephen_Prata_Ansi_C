// выводит целые числа в двоичной форме
#include <stdio.h>

void to_binary(unsigned long n);

int binary(void) {
	
	unsigned long number;
	printf("Enter integer number (q for finishing):\n");
	while(scanf("%lu", &number) == 1) {
		printf("Binary equivalent: ");
		to_binary(number);
		putchar('\n');
		printf("Enter integer number ('q' for finishing):\n");
	}
	printf("Program is finished.\n");
	return 0;
}

void to_binary(unsigned long n) { // рекурсивная функция
	int r;
	
	r = n % 2;
	if(n >= 2) to_binary(n/2);
	putchar(r == 0 ? '0' : '1');
	return;
}
