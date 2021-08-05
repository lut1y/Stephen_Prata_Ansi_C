// использование функций fgets() и fputs()
#include <stdio.h>
#define STLEN 15

int fgets1(void) {
	char words[STLEN];
	
	puts("Enter string.");
	fgets(words, STLEN, stdin); // сохраняет и \n
	printf("Your string, print twice (with help puts(), and then fputs()):\n");
	puts(words);
	fputs(words, stdout);
	puts("Enter more one string.");
	fgets(words, STLEN, stdin);
	printf("Your string, entered twice (with help puts(), and then fputs()):\n");
	puts(words);
	fputs(words, stdout); // не добавялет \n
	puts("Ready.");	
	
	return 0;
}
