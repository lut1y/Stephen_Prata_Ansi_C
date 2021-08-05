// пять видов операторов
#include <stdio.h>

int task5(void) {
	int count, sum, days;
	
	count = 0;
	sum = 0;
	days = 0;
	
	printf("Enter count days: ");
	scanf("%d", &days);
	while(++count <= days) {
		sum += count;
		printf("%d + ", count);
	}
		
	printf("\b\b= $%d\n", sum);
	
	return 0;
}
