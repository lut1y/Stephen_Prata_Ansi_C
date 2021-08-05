// вносит изменения во все входные данные, сохраняя пробелы
#include <stdio.h>
#define SPACE ' ' // кавычка, пробел, кавычка

int cypher1(void) {
	char ch;
	
	while((ch = getchar()) != '\n') {
		if(ch == SPACE)
			putchar(ch);
		else
			putchar(ch + 1);
	}
	putchar(ch);
	
	return 0;
}
