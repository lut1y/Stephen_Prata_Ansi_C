// повторяет на экране ввод до достижения конца файла
#include <stdio.h>

int echo_eof(void) {
	int ch;
	
	while((ch = getchar()) != EOF)
		putchar(ch);
	// В Windows <Ctrl+Z> - это EOF
	return 0;
}
