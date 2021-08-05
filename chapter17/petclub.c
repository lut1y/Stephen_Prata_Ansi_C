// using binary tree of search
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);

int petclub(void) {
	Tree pets;
	char choice;
	
	InitializeTree(&pets); // инициализируем дерево
	while((choice = menu()) != 'q') {
		switch(choice) {
			case 'a': addpet(&pets);
				break;
			case 'l': showpets(&pets);
				break;
			case 'f': findpet(&pets);
				break;
			case 'n': printf("%d animals in club \n", \
				TreeItemCount(&pets));
				break;
			case 'd': droppet(&pets);
				break;
			default: puts("Error in switch");
		}
	}
	DeleteAll(&pets);
	puts("Program is finished.");

	
	return 0;
}

char menu(void) {
	int ch;
	
	puts("Program of membership in club Nerfville Pet Club");
	puts("Enter letter, corresponding your choice:");
	puts("a) adding animal		l) output list of animals");
	puts("n) count of animals		f) search of animals");
	puts("d) removing of animals		q) quit");
	
	while((ch = getchar()) != EOF) {
		while(getchar() != '\n') continue;
		ch = tolower(ch);
		if(strchr("alrfndq", ch) == NULL)
			puts("Enter letter a, l, f, n, d or q:");
		else
			break;
	}
	if(ch == EOF) ch = 'q';
	
	return ch;
}

void addpet(Tree *pt) {
	Item temp;
	
	if(TreeIsFull(pt))
		puts("In club have not more place!");
	else {
		puts("Enter animal's name:");
		s_gets(temp.petname, SLEN);
		puts("Enter kind of animal:");
		s_gets(temp.petkind, SLEN);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddItemT(&temp, pt);
	}
}

void showpets(const Tree *pt) {
	if(TreeIsEmpty(pt))
		puts("Records are absents!");
	else
		TraverseT(pt, printitem);
}

void printitem(Item item) {
	printf("Animals: %-19s  Kind: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree *pt) {
	Item temp;
	
	if(TreeIsEmpty(pt)) {
		puts("Records are absent!");
		return;
	}
	puts("Enter animal's name, which you want found:");
	s_gets(temp.petname, SLEN);
	puts("Enter kind of animal:");
	s_gets(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s that named %s ", temp.petkind, temp.petname);
	if(InTree(&temp, pt))
		printf("is member of club.\n");
	else
		printf("isn't member of club.\n");
}

void droppet(Tree *pt) {
	Item temp;
	
	if(TreeIsEmpty(pt)) {
		puts("Records are absent!");
		return;
	}
	puts("Enter animal's name, which need remove from club:");
	s_gets(temp.petname, SLEN);
	puts("Enter kind of animals:");
	s_gets(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s named %s ", temp.petkind, temp.petname);
	if(DeleteItem(&temp, pt))
		printf("remove from club.\n");
	else
		printf("isn't member of club.\n");
}

void uppercase(char *str) {
	while(*str) {
		*str = toupper(*str);
		str++;
	}
}

//char *s_gets(char *st, int n) {
//	char *ret_val;
//	char *find;
//	
//	ret_val = fgets(st, n, stdin);
//	if(ret_val) {
//		find = strchr(st, '\n');
//		if(find)
//			*find = '\0';
//		else
//			while(getchar() != '\n') continue;
//	}
//	return ret_val;
//}
