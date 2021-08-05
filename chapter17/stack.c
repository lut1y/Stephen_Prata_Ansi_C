#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void InitializeStack(Stack *ps) { 
	ps->top = 0;	
}

bool FullStack(const Stack *ps) {
	if(ps->top == MAXSTACK)
		return true;
	return false;
}

bool EmptyStack(const Stack *ps) {
	if(ps->top < 0)
		return true;
	return false;
}
	
bool Push(Item item, Stack *ps) {
	
	if(FullStack(ps))
		return false;
	
	ps->item[ps->top] = item;
	ps->top++;
	
	return true;
}

bool Pop(Item *pitem, Stack *ps) {
	if(EmptyStack(ps))
		return false;
	
	*pitem = ps->item[ps->top];
	ps->top--;
	
	return true;
}
