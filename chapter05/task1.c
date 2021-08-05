#include <stdio.h>

int task1(void) {
	const int MIN_PER_HOUR = 60;
	int min;
	
	printf("Enter minutes (0=>for exit): ");
	scanf("%d", &min);
	while(min>0) {
		printf("%d minutes corresponds %d hour(s) %d minute(s)",
			min, min/MIN_PER_HOUR, min % MIN_PER_HOUR);
		printf("\nEnter minutes (0=>for exit): ");
	scanf("%d", &min);
	}
	return 0;
}
