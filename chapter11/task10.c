#include <stdio.h>
#include <string.h>

void *strdelspace(char *st);

int task10(void) {
	
	char s[] = "It's ok. It's all right.";
	puts(s);
	strdelspace(s);
	puts(s);
	
	return 0;
}

void *strdelspace(char *st) {
	char *s1;
	
	while(*st) {
		if(*st == ' ') {
			s1 = st;
			while(*s1) {
				*s1 = *(s1 + 1);
				s1++;
			}
		}
		else
			st++;
	}
}
