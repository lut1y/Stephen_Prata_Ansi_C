// считывает строки и сортирует их
#include <stdio.h>
#include <string.h>

#define SIZE 81
#define LIM 20
#define HALT ""

void ststr(char *strings[], int num);
char *s_gets(char *st, int n);

int sort_str(void) {
	char input[LIM][SIZE];
	char *ptstr[LIM];
	int ct=0;
	int k=0;
	
	printf("Enter before %d strings, and they will be sort.\n", LIM);
	printf("To stop input, press key <ENTER> in start of string.\n");
	while(ct<LIM && s_gets(input[ct], SIZE) != NULL
			&& input[ct][0] != '\0') {
		ptstr[ct] = input[ct];
		ct++;			
	}
	ststr(ptstr, ct);
	puts("\nSorted list:\n");
	for(k=0; k<ct; k++)
		puts(ptstr[k]);
		
	return 0;
}

void ststr(char *strings[], int num) {
	char *temp;
	int top, seek;
	
	for(top = 0; top < num-1; top++)
	// самый "верхний" элемент
		for(seek = top + 1; seek < num; seek++)
			// "верхний" элемент сравнивается со всеми остальными
			if(strcmp(strings[top], strings[seek]) > 0) {
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}
