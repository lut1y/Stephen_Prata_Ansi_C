#include <stdio.h>
#include <string.h>

#define ANSWER "Grant"
#define SIZE 40
char *s_get(char *st, int n);

int compare(void) {
	char try[SIZE];
	
	puts("Who is buried in Grant's grave?"); //  то похоронен в могиле √ранта?
	s_gets(try, SIZE);
	while(strcmp(try, ANSWER) != 0) { // посто€нный цикл, т.к. try и ANSWER должны начинатьс€ с одной €чейки пам€ти
		puts("Wrong! Try again.");
		s_gets(try, SIZE);
	}
	puts("Now is right!");
	
	return 0;
}
