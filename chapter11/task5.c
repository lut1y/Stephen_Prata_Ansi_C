#include <stdio.h>

#define SIZE 20

char *s_gets2(char *, int);
char *mystrchr(char *, char);

int task5(void) {
	char *str;
	char ch;
	char *res;
	
	puts("Enter string.");
	s_gets2(str, SIZE);	
	printf("Enter symbol: ");
	scanf("%c", &ch);
	
	res = mystrchr(str, ch);
	
	printf("Position: %s\n", res);	
	
	return 0;
}

char * mystrchr(char *p, char ch) {
	
	while(*p) {
		if(*p == ch)
			return p;
		p++;
	}
	return NULL;
}
