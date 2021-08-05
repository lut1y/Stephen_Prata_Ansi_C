#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int task12(void) {
	char ch;
	int ct_word = 0;
	int ct_let_low = 0;
	int ct_let_up = 0;
	int ct_punct = 0;
	int ct_digit = 0;
	bool inword = false;
	
	
	while((ch = getchar()) != EOF) {
		if(islower(ch))
			ct_let_low++;
		if(isupper(ch))
			ct_let_up++;
		if(isdigit(ch))
			ct_digit++;
		if(ispunct(ch))
			ct_punct++;
		if(!inword && !isspace(ch)) {
			inword = true;
			ct_word++;
		}
		if(inword && isspace(ch))
			inword = false;
	}
		
		printf("\nwords = %d, lowercase = %d, uppercase = %d, "
			"digits = %d, punctuation = %d\n",
			ct_word, ct_let_low, ct_let_up, ct_digit, ct_punct);
	
	return 0;
}
