// using of array's structure
#include <stdio.h>
#include <string.h>

#define TSIZE 45	// max size for saving name
#define FMAX  5

struct film {
	char title[TSIZE];
	int rating;
};
char *s_gets(char *st, int n);

int films1(void) {
	struct film movies[FMAX];
	int i=0;
	int j;
	
	puts("Enter name of first film: ");
	while(i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && 
			movies[i].title[0] != '\0') {
		puts("Enter your value of rating <0-10>:");
		scanf("%d", &movies[i++].rating);
		while(getchar() !='\n') continue;
		puts("Enter name of next film (or empty string for finish entering):");
	}
	if(i==0)
		printf("Data is not entered");
	else
		printf("Lists of films:\n");

	for(j=0; j<i; j++)
		printf("Film: %s Rating: %d\n", movies[j].title,
			movies[j].rating);
	printf("Program is finished.\n");
	return 0;
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if(ret_val) {
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}

