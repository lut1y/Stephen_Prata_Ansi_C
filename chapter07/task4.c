#include <stdio.h>
#include <ctype.h>

int task4(void) {
	char ch;
	int change;
	
	while((ch = getchar()) != '#') {
		if(ch == '.') {
			putchar('!');
			change++;
		} else 
			if (ch == '!'){
			printf("!!");
			change++;
		} else
			putchar(ch);
	}
	printf("In this sentence was %d changes:\n");
	return 0;
}
