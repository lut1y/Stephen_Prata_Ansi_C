#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

char *s_gets(char *st, int n);

int task5(void) {
	Stack stk;
	Item item;
	
	InitializeStack(&stk);
	
	puts("Enter string: ");
	while((item.ch = getchar()) != '\n' && Push(item, &stk)) ;	
	
	
	while(!EmptyStack(&stk)) {
		Pop(&item, &stk);
		putchar(item.ch);
	}
	
	return 0;
}
