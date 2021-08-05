#include <stdio.h>
#define MAX 100

int bottles(void) {
	int count = MAX + 1;
	while(--count > 0) {
		printf("%d bottles beer in shelves, "
			"%d bottles beer!\n", count, count);
		printf("take one from these and run in a circle, \n");
		printf("%d bottles beer!\n\n", count-1);
	}
	
	return 0;
}
