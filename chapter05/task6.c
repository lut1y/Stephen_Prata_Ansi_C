// пять видов операторов
#include <stdio.h>

int task6(void) {
	int count, sum, days;
	
	count = 0;
	sum = 0;
	days = 0;
	
	printf("Enter count days: ");
	scanf("%d", &days);
	while(++count <= days) {
		sum += count*count;
		printf("%d + ", count*count);
	}
		
	printf("\b\b= $%d\n", sum);
	
	return 0;
}
