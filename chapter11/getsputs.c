// ������������� ������� gets() � puts()
#include <stdio.h>
#define STLEN 81

int getsputs(void) {
	char words[STLEN];
	
	puts("Enter string.");
	gets(words);
	printf("Your string, entered twice:\n");
	printf("%s\n", words);
	puts(words); // ������������� + \n
	puts("Ready.");
	
	return 0;
}
