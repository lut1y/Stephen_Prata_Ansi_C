#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

char *s_gets2(char *st, int n);

int task15(void) {
	char * str;
	bool b = true;
	
	puts("Enter string.");
	s_gets(str, 11);
	
	while(*str != '\0')
		if(!isdigit(*str++)) {
			b = false;
			break;
		}
	if(b)
		puts("This number is ready.");
	else
		puts("This number contains not digit symbols.");
	
	return 0;
}
