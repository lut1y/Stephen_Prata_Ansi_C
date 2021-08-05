// будет ли это работать?
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ANSWER "Grant"
#define SIZE 40

char *s_gets(char *st, int n);
int nogo(void) {
	char try[SIZE];
	puts("Who is buried in Grant's grave?"); //  то похоронен в могиле √ранта?
	s_gets(try, SIZE);
	while(try != ANSWER) { // посто€нный цикл, т.к. try и ANSWER должны начинатьс€ с одной €чейки пам€ти
		puts("Wrong! Try again.");
		s_gets(try, SIZE);
	}
	puts("Now is right!");
	
	return 0;
}
