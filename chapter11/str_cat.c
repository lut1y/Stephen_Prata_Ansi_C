// объединяет две строки
#include <stdio.h>
#include <string.h> // объединение strcat()

#define SIZE 80

char *s_gets(char *st, int n);

int str_cat(void) {
	char flower[SIZE];
	char addon[] = " smells like old felt boots.";
	
	puts("What is your favourite flower?");
	if(s_gets(flower, SIZE)) {
		strcat(flower, addon);
		puts(flower);
		puts(addon);
	} else
		puts("Discovered end of file!");
	puts("Program is finished.");
	
	return 0;
}
