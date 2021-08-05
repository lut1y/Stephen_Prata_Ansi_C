#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int task4(void) {
	int ch,
		n_chars=0,
		n_words=0;
	bool inword = false; // true - внутри слова
	
	
	while( (ch = getchar()) != EOF) {
		if(isalpha(ch))
			n_chars++;
		if(!(isspace(ch) || ispunct(ch)) && !inword) {
			// если первая буква слова
			inword = true;
			n_words++;
		}
		if((isspace(ch) || ispunct(ch)) && inword)
			inword = false;
		
	}
	printf("Symbols: %d\n", n_chars);
	printf("Words: %d\n", n_words);
	printf("Average count letters in words is %d.\n", (int) n_chars/n_words);
	return 0;
}
// Hello, my dear friend! 
