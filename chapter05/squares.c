// генерирует таблицу квадратов 20 значений
#include <stdio.h>

int squares(void) {
	
	int num = 1;
	while(num < 21) {
		printf("%4d %6d\n", num, num*num);
		num = num + 1;
	}
	return 0;
}
