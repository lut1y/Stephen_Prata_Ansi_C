#include <stdio.h>

#define SIZE 10

char *getnchar(char *, int);

int task1(void) {
	char a[10];
	int i;
	
	puts("Enter strings.");
	getnchar(a, SIZE);
	
	for(i=0; i<SIZE; i++)
		printf("%c ", a[i]);
	putchar('\n');
	
	return 0;
}

char *getnchar(char *st, int n) {
	char ch;
	int i=0;
	
	while((ch = getchar()) != EOF && i < n) {
		*st = ch;		
		st++;
		i++;
	}		
	
}
