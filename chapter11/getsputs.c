// использование функций gets() и puts()
#include <stdio.h>
#define STLEN 81

int getsputs(void) {
	char words[STLEN];
	
	puts("Enter string.");
	gets(words);
	printf("Your string, entered twice:\n");
	printf("%s\n", words);
	puts(words); // автоматически + \n
	puts("Ready.");
	
	return 0;
}
