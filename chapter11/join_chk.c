// объединяет две строки, предварительно проверив размер
#include <stdio.h>
#include <string.h>

#define SIZE 31
#define BUGSIZE 13

char *s_gets(char *s, int n);
int join_chk(void) {
	char flower[SIZE];
	char addon[] = " smells as old felt boots.";
	char bug[BUGSIZE];
	int available;
	
	puts("What is your favourite flower?");
	s_gets(flower, SIZE);
	if((strlen(addon) + strlen(flower) + 1) <= SIZE)
		strcat(flower, addon);
	puts(flower);
	
	puts("What is your favourite bug?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
			//  13 - 5 - 1 = 7 
	strncat(bug, addon, available);
	puts(bug);
	
	return 0;
}
