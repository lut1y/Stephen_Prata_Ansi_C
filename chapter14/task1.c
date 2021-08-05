#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LEN 10

char *s_gets(char *st, int n);

struct month {
	char name[LEN];
	char abbr[4];
	short int ct_day;
	short int num;
};

struct month months[12] = {
		{ "January", "jan", 31, 1 },
		{ "February", "feb", 28, 2 },
		{ "March", "mar", 31, 3 },
		{ "April", "apr", 30, 4 },
		{ "May", "may", 31, 5 },
		{ "Juny", "jun", 30, 6 },
		{ "July", "jul", 31, 7 },
		{ "August", "aug", 31, 8 },
		{ "September", "sep", 30, 9 },
		{ "Octomber", "oct", 31, 10 },
		{ "November", "nov", 30, 11 },
		{ "December", "dec", 31, 12 }
	};

int task1(void) {
	int i;
	char mon[LEN];
	bool sovp;
		
	printf("Enter name of month: ");
	while(s_gets(mon, LEN) != NULL && mon[0] != '\0') {
		sovp = false;
		for(i = 0; i < 12; i++) {
			if(strcmp(mon, months[i].name) == 0) {
				sovp = true;
				break;
			}
		}
		if(sovp) {
			printf("%s contains %d days.\n", months[i].name,
				months[i].ct_day);
		} else {
			printf("Name of month is not valid.\n");
		}
		printf("Enter next name of month (or empty string - exit): ");
	}
	printf("Program is finished.\n");
	return 0;
}
