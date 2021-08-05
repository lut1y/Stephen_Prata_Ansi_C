#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "treew.h"

char menu_(void);
void printwords(const Tree *pt);
void printitem_(Item item);

int task7(void) {
	Tree words;
	FILE *fp;
	Item temp;
	char buf[20];
	char choice;
	
	if((fp = fopen("treew.c", "r")) == NULL) {
		fputs("Cannot open file", stderr);
		exit(EXIT_FAILURE);
	}
	
	InitializeTree(&words);
	
	// Читаем слова	
	while(fscanf(fp, "%s", buf) == 1 && !TreeIsFull(&words)) {
		strcpy(temp.word, buf);		
		AddItemW(&temp, &words);
	}
	
	while((choice = menu_()) != 'q') {
		switch(choice) {
			case 'a':
				printwords(&words);
				break;
			case 'b':
				findword(&words);
				break;
			default:
				printf("Error command!");
		}
	}
		
	return 0;
}

void findword(const Tree *words) {
	char wrd[20];
	Item item;
	const Item *pi;
	
	if(TreewIsEmpty(words)) {
		puts("No words!");
		return;
	}
	printf("Enter word: ");
	if(scanf("%s", wrd) == 1) {
		strcpy(item.word, wrd);
		if((pi = WhereInTree(&item, &words)) == NULL) 
			printf("%s is not in the list.\n");
		else
			printf("%s appears %d times.\n", wrd, pi->count);
	}
	while(getchar() != '\n') continue;
}

void printwords(const Tree *pt) {
	if(TreewIsEmpty(pt))
		puts("Tree is empty!");
	else
		TraverseW(pt, printitem_);
}

void printitem_(Item item) {
	printf("Word: %-19s Count: %d\n", item.word, item.count);
}

char menu_(void) {
	int ch;
	
	puts("Choice punct:");
	puts("a) print all words;");
	puts("b) find word;");
	puts("q) quit;");
	printf("Your choice: ");
	
	while((ch = getchar()) != EOF) {
		while(getchar() !='\n') continue;
		ch = tolower(ch);
		if(strchr("abq", ch) == NULL)
			puts("Please enter a, b or q:");
		else
			break;
	}
	if(ch == EOF) ch = 'q';
	return ch;	
}
