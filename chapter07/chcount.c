// использование логической операции "»"
#include <stdio.h>
#define PERIOD '.'

int chcount(void) {
	char ch;
	int charcount = 0;
	
	while((ch = getchar()) != PERIOD) {
		if(ch !='"' && ch != '\'')
			charcount++;
	}
	printf("There is have %d symbols, that is not quotes.\n", charcount);
	
	return 0;
}
