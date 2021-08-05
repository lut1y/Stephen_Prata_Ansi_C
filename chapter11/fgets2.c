// использование функций fgets() и fputs()
#include <stdio.h>
#define STLEN 10

int fgets2(void) {
	char words[STLEN];
	
	puts("Enter strings (or empty string for exit from program):");
	while(fgets(words, STLEN, stdin) != NULL && words[0]!= '\n')
		fputs(words, stdout);
	puts("Ready.");
	
	return 0;
}
