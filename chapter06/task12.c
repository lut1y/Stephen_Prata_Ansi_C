#include <stdio.h>

int task12(void) {
	int limit;
	int count;
	float sum;
	
	printf("Enter limit of sequence: ");
	scanf("%d", &limit);
	
	for(count=1, sum=0.0; count<=limit; count++) {
		sum += 1.0 / count;
	}	
	printf("1.0 + 1.0/2.0 + 1.0/3.0 + ... = %.4f\n", sum);
	
	for(count=1, sum=0.0; count<=limit; count++) {
		if(count % 2 == 0)
			sum -= 1.0 / count;
		else
			sum += 1.0 / count;
	}	
	printf("1.0 - 1.0/2.0 + 1.0/3.0 + ... = %.4f\n", sum);
	
	return 0;
}
