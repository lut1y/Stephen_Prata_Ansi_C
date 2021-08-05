#include <stdio.h>

int task5(void) {
	char ch;
	int change;
	
	while((ch = getchar()) != '#') {
		switch (ch) {
		case '.':
			putchar('!');
			change++;
			break;
		case '!':
			printf("!!");
			change++;
			break;	
		default:
			putchar(ch);	
		}
	}
	printf("\nIn this sentence was %d changes:\n", change);
	return 0;
}
