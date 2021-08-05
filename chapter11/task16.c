#include <stdio.h>
#include <ctype.h>
#include <string.h>

int task16(int argc, char *argv[]) {
	char p = 'p';
	char ch;
	
	if(argc > 2) {
		printf("Usage: %s [-p | -u | -l]\n", argv[0]);
	} else {
		if(argc == 2)
			if(argv[1][0] == '-' && strlen(argv[1]) == 2)
				p = argv[1][1];
			else p = '\0';
			
		switch(p) {
		case 'u': 
			while((ch = getchar()) != EOF)
				putchar(toupper(ch));
			break;
		case 'l': 
			while((ch = getchar()) != EOF)
				putchar(tolower(ch));
			break;
		case 'p': 
			while((ch = getchar()) != EOF) putchar(ch);
			break;
		default:
			printf("Usage: %s [-p | -u | -l]\n", argv[0]);
		}
	}
	return 0;
}
	

