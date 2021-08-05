#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);
void reverse_word(char *st);

int task9(void) {
	char *str;
	
	s_gets(str, 20);
	puts(str);	
	
	reverse_word(str);
	puts(str);
	
	return 0;
}

void reverse_word(char *st) {
	int len = strlen(st),
		i;
	char temp;
	
	for(i=0; i<len/2; i++) {
		temp = *(st + i);
		*(st + i) = *(st + (len - 1) - i);
		*(st + (len-1) - i) = temp;
	}
		
}
