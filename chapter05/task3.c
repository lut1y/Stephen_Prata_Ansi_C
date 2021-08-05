#include <stdio.h>

int task3(void) {
	const int DAYS_PER_WEEK = 7;
	int days;
	
	printf("Enter days ((days < 0) => for exit): ");
	scanf("%d", &days);
	while(days>0) {
		printf("%d days corresponds %d week(s) and %d day(s)",
			days, days/DAYS_PER_WEEK, days % DAYS_PER_WEEK);
		printf("\nEnter days ((days < 0) => for exit): ");
	scanf("%d", &days);
	}
	return 0;
}
