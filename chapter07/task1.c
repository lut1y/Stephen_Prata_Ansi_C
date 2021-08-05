#include <stdio.h>
#include <ctype.h>

int task1(void) {
	char ch;
	int c_space=0;
	int c_new_str=0;
	int c_oth_sym=0;
	
	while((ch = getchar()) != '#') {
		if(ch == ' ') 
			c_space++;
		else
			if(ch =='\n') 
				c_new_str++;
			else
				c_oth_sym++;
	}
	printf("There were entered next symbols:\n"
		"\tspace: %d\n\tnew string: %d\n\tother symbols: %d\n", 
		c_space, c_new_str, c_oth_sym);	
	return 0;
}
