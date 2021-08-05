// неправильное применение операции =
#include <stdio.h>

int trouble(void) {
	long num;
	long sum = 0L;
	int status;
	printf("Enter decimal number for subsequent summing: ");
	printf("(or 'q' for finish program): ");
	status = scanf("%ld", &num);
	while(status = 1) {
		sum += num;
		printf("Enter next decimal number (or 'q' for finish program): ");
		status = scanf("%ld", &num);
	}
	printf("Sum entered numbers equals %ld.\n", sum);
	
	return 0;
}
