#include <stdio.h>

int for_char(void) {
	char ch; 
	for(ch = 'a'; ch <= 'z'; ch++)
		printf("Value ASCII for %c equals %d\n", ch, ch);
	return 0;
}
