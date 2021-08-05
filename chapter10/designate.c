// использование назначенных инициализаторов
#include <stdio.h>
#define MONTHS 12

int designate(void) {
	int days[MONTHS] = { 31, 28, [4] = 31, 30, 31, [1] = 29 };
	int index;

	for(index = 0; index < MONTHS; index++)
	printf("%2d %d\n", index+1,
		days[index]);	
	
	return 0;
}
