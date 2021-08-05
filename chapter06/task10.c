#include <stdio.h>

int square(int n);

int task10(void) {
	int low, up;
	int i, sum;
	
	printf("Press low and up decimal limits: ");
	scanf("%d %d", &low, &up);
	while(low < up) {
		sum=0;
		for(i=low; i<=up; i++) sum += square(i);
		printf("Sum squares of decimal numbers from %d to %d equals %d\n",
			square(low), square(up), sum);
		printf("Press low and up decimal limits: ");		
		scanf("%d %d", &low, &up);
	}
	
	printf("Work is finished!");
	return 0;
}

int square(int n) {
	return n*n; 
}
