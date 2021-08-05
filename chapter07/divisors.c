// вложенные оперторы if отображают делители числа
#include <stdio.h>
#include <stdbool.h>

int divisors(void) {
	unsigned long num;	// проверяемое число
	unsigned long div; 	// потенциальные делители
	bool isPrime;		// флаг простого числа
	printf("Enter decimal number for analysis;");
	printf("for finishing press q.\n"); 
	while(scanf("%lu", &num) == 1) {
		for(div = 2, isPrime = true; (div*div) <= num; div++) {
			if(num % div == 0) {
				if((div*div) != num)
					printf("%lu divides on %lu and %lu.\n",
						num, div, num/div);
				else
					printf("%lu divides on %lu.\n",
						num, div);
				isPrime = false; // число не является простым
			}
		}
		if(isPrime)
			printf("%lu is prime number.\n", num);
		printf("Enter decimal number for analysis;");
		printf("for finishing press q.\n");
	}
	printf("Good Bye!");
	return 0;
}
