#include <stdio.h>
#include <ctype.h>

int orderNumberLetter(char);

int task7(void) {
	int ch, i=0;
	
	
	while((ch = getchar()) != EOF) {
		if(orderNumberLetter(ch) == -1)
			continue;
		else {
			printf("%c-%d ", ch, orderNumberLetter(ch));			
			if(i<=10)
				i++;
			else {
				putchar('\n');
				i=0;				
			}
		}
	}
	return 0;
}

int orderNumberLetter(char ch) {
	ch = tolower(ch);
	if(!isalpha(ch))
		return -1;
	else
		return ch-96;
	
}
