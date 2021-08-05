// using of linked list's structure
#include <stdio.h>
#include <stdlib.h>	// malloc()
#include <string.h>	// stcpy()

#define TSIZE 45	// max size for saving name

typedef struct film {
	char title[TSIZE];
	int rating;
	struct film *next;
} film;
char *s_gets(char *st, int n);

int films2(void) {
	film *head = NULL;
	film *prev, *current;
	char input[TSIZE];

	// Getting and saving information
	puts("Enter name of first film: ");
	while(s_gets(input, TSIZE) != NULL && input[0] != '\0') {
		current = (film *) malloc(sizeof(film));
		if(head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your value of rating <0-10>:");
		scanf("%d", &current->rating);
		while(getchar() != '\n') continue;
		puts("Enter name of next film (or empty string for finishing entering): ");
		prev = current;		
	}
	// Display list of films
	if(head == NULL)
		printf("Data is not entered.");
	else
		printf("List of film:\n");
	current = head;
	while( current != NULL) {
		printf("Film: %s Rating: %d\n",	current->title, current->rating);
		current = current->next;
	}
	// Program is finished, because be can free memory
	current = head;
	while(current != NULL) {
		current = head;
		head = current->next;
		free(current);
	}
	printf("Program is finished.\n");
	return 0;
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
//			while(getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}

