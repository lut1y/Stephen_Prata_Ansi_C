#include <stdio.h>
#include <ctype.h>
#define SIZE 10

char *getword(char *str);

int task3(void) {
	char input[SIZE];
	
	while(getword(input) != NULL)
		puts(input);
	puts("Done");
	
	return 0;
}

char *getword(char *str) {
	int ch;
	char *orig = str;
	
	// убираем передние пробелы
	while((ch=getchar()) != EOF && isspace(ch))
		continue;
	if(ch == EOF) 
		return NULL;
	else
		*str++ = ch;
	
	while((ch=getchar()) != EOF && !isspace(ch))
		*str++ = ch;
	*str = '\0';
	if(ch == EOF)
		return NULL;
	else {
		while(ch != '\n') ch = getchar();
		return orig;
	}
	
}
