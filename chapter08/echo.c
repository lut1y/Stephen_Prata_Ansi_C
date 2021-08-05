// повторяет ввод
#include <stdio.h>

int echo(void) {
	char ch;
	
	while((ch = getchar()) != '#')
		putchar(ch);
	return 0;
}
