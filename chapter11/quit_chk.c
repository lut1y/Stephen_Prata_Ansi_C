// начало некоторой программы
#include <stdio.h>
#include <string.h>

#define SIZE 80
#define LIM 10
#define STOP "quit"

char *s_gets(char *st, int n);

int quit_chk(void) {
	char input[LIM][SIZE];
	int ct = 0;
	
	printf("Enter until %d strings (or 'quit' for finishing):\n", LIM);
	while(ct < LIM && s_gets(input[ct], SIZE) != NULL &&
			strcmp(input[ct], STOP) != 0)
		ct++;
	printf("Entered %d string(s)\n", ct);
	
	return 0;	
}
