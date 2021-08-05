// пять видов операторов
#include <stdio.h>

int addemup(void) {
	int count, sum;
	
	count = 0;
	sum = 0;
	while(count++ < 20)
		sum += count;
	printf("sum = %d\n", sum);
	
	int x = 1;
	printf("(4 + x++) + (6 + x++) = %d, where x = 1", (4 + x++) + (6 + x++));
	
	return 0;
}
