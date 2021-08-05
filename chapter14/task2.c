#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10

char *s_gets(char *st, int n);

struct month {
	char name[LEN];
	char abbr[4];
	short int ct_day;
	short int num;
};

extern struct month months[12];

int task2(void) {
	int i, total;
	int day, num_mon, year;
	char mon[LEN];
	bool sovp;
	
	printf("Enter date: ");
	while(scanf("%d %s %d", &day, mon, &year) == 3) {
		sovp = false;
		total = 0;
		if((num_mon = atoi(mon)) == 0) {
			for(i = 0; i < 12; i++) {				
				if(strcmp(mon, months[i].name) == 0 ||
						strcmp(mon, months[i].abbr) == 0) {
					sovp = true;
					num_mon = i + 1;
					break;				
				}
			}
		} else 
			sovp = true; 

		if(sovp) {
			for(i = 0; i < num_mon - 1; i++)
				total += months[i].ct_day;
			total += day;
			if(year % 4 == 0) total += 1;
			printf("%d days have passed since the beginning of the year.\n", total);			
		} else
			puts("Month is invalid.");
		printf("Enter next date (or 'q' - exit): ");
		while(getchar() != '\n') continue;
	}
	printf("Program is finished.\n");
	return 0;
}
