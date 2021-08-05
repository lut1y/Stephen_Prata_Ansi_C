// мен€ем входнные данные, оставл€€ неизменными символы,
// которые не €вл€ютс€ буквами
#include <stdio.h>
#include <ctype.h>	// дл€ доступа к isalpha()

int cypher2(void) {
	char ch;
	
	while((ch = getchar()) != '\n') {
		if(isalpha(ch))
			putchar(ch+1);
		else
			putchar(ch);
	}
	putchar(ch);
	
	return 0;
}
