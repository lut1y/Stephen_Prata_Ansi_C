// предоставление компилятору возможности подсчета элементов
#include <stdio.h>

int day_mon2() {
	const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int index;

	for(index = 0; index < sizeof(days) /  sizeof(int); index++)
	printf("Month %d has %2d day(s).\n", index+1,
		days[index]);	
	
	return 0;
}
