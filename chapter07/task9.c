#include <stdio.h>
#include <stdbool.h>

int task9(void) {
	unsigned long num,
				i, div;
	bool isPrime;
		
	printf("Enter number: ");
	while(scanf("%lu", &num) == 1) {
		if(num < 1) {
			printf("This number is not positive!\n");
		} else {
			for(i = 2; i <= num; i++) { 
				// проверяем каждое число до указанного
				for(div = 2, isPrime=true; (div*div)<=i; div++) {
					if(i % div == 0) {
						
						isPrime = false; // число не является простым
						break;
					}
				}
				if(isPrime)
					printf("%lu ", i);
			}
		}
		printf("\n");
		printf("\nEnter next number (press 'q' for finishing): ");	
	}	
	
	return 0;
}
