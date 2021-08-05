#include <stdio.h>

int task2(void) {
	int ch;
	unsigned short int c_sym=0;
	
	while( (ch=getchar()) != EOF) {
		switch (ch) {
			case '\n':
				printf("'\\n'-%d ", ch);
				break;
			case '\t':
				printf("'\\t'-%d ", ch);
				break;
			case ' ':
				printf("' '-%d ", ch);
				break;
			default:
				printf("%c-%d ", ch, ch);
		}
		c_sym++;
		if(c_sym == 10) {
			printf("\n");
			c_sym = 0;
		}
	}
	
	printf("Program is finished.\n");
	return 0;
}
