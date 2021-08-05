// выводит строку и подписывает символы
#include <stdio.h>
int put2(const char* string) {
	int count = 0;
	
	while(*string) { // *string != '\0'
		putchar(*string++);
		count++;
	}
	putchar('\n');
	
	return(count);
}
