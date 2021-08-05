// выводит количество дней в каждом месяце
#include <stdio.h>
#define MONTHS 12

int day_mon1() {
	int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int index;

	for(index = 0; index < MONTHS; index++)
	printf("Month %d has %2d day(s).\n", index+1,
		days[index]);	
	
	return 0;
}
