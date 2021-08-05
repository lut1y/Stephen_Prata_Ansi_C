#include <stdio.h>
#include <string.h>

int task7(void) {
	char word[40];
	int i;
	
	printf("Enter word: ");
	gets(word);
	
	printf("Reverse order: ");
	for(i = strlen(word); i >= 0; i--) {
		printf("%c", word[i]);
	}
	printf("\n");
	return 0;
}
