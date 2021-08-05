// using linked list in style ADT
// compile with list.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void showmovies(Item item);
char *s_gets(char *st, int n);

int films3(void) {
	List movies;
	Item temp;
	
	// initialization
	InitializeList(&movies);
	if(ListIsFull(&movies)) {
		fprintf(stderr, "Available memory is absent! Program is finished.\n");
		exit(1);
	}

	// Getting and saving
	puts("Enter name of first film:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your value of rating <0-10>:");
		scanf("%d", &temp.rating);
		while(getchar() != '\n') continue;
		if(AddItem(temp, &movies) == false) {
			fprintf(stderr, "Problem with allocate memory\n");
			break;
		}
		if(ListIsFull(&movies)) {
			puts("List is full");
			break;
		}
		puts("Enter name of next film (or empty string for finishing of entering):");
	}

	// Display
	if(ListIsEmpty(&movies))
		printf("Data is not entered.\n");
	else {
		printf("List of films:\n");
		Traverse(&movies, showmovies);
	}
	printf("You entered %d films.\n", ListItemCount(&movies));

	// clearning
	EmptyTheList(&movies);
	printf("Program is finished.\n");

	return 0;
}

void showmovies(Item item) {
	printf("Film: %s Rating: %d\n", item.title, item.rating);
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
