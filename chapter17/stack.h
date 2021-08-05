#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

#define MAXSTACK 100
typedef struct item {
	char ch;
} Item;

typedef struct stack {
	Item item[MAXSTACK];
	int top;
} Stack;

void InitializeStack(Stack *ps);
bool FullStack(const Stack *ps);
bool EmptyStack(const Stack *ps);
bool Push(Item item, Stack *ps);
bool Pop(Item *pitem, Stack *ps);

#endif
