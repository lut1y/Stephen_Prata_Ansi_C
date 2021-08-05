#include <stdio.h>

unsigned long rFibonacci(unsigned n);
unsigned long Fibonacci(unsigned n);

int task11(void) {
	unsigned n;
	int i;
	
	printf("Enter number: ");
	while(scanf("%u", &n) == 1) {
		printf("rFibonacci: ");
		for(i=1; i<=n; i++)
			printf("%u ", rFibonacci(i));
		printf("\n");
		
		printf(" Fibonacci: ");
		for(i=1; i<=n; i++)
			printf("%u ", Fibonacci(i));
		printf("\n");
		
		printf("Enter next number: ");
	}
	return 0;
}

unsigned long rFibonacci(unsigned n) {
	if(n>2) {
		return rFibonacci(n-1) + rFibonacci(n-2);
	}	
	else
		return 1;
}



unsigned long Fibonacci(unsigned n) {
	int i;
	unsigned long fib = 0,
				  fib1 = 1, 
				  fib2;
	if(n <= 2) 
		fib2 = 1;
	else {
		for(i=2; i<=n; i++) {
			fib2 = fib1 + fib;
			fib = fib1;
			fib1 = fib2; 
		}
	}
	return fib2;
}
