// использование цикла for для построения таблицы кубов
#include <stdio.h>

int for_cube(void) {
	int num;
		
	printf("    n  n in cube\n");
	for(num = 1; num <= 6; num++)
		printf("%5d  %5d\n", num, num*num*num);
	return 0;
}
