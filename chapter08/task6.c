#include <stdio.h>
#include <ctype.h>

char get_choice_(void);
char get_first_(void);
int get_int(void);
void count(void);

int task6(void) {
	int choice;
	void count(void);
	while( (choice = get_choice_()) != 'q') {
		switch(choice) {
			case 'a': // advice - совет
				printf("Buy low, sell high.\n");
				break;
			case 'b': // bell - звонок
				putchar('\a'); // ANSI
				break;
			case 'c': // counter - подсчет  
				count();
				break;
			default: 
				printf("Error!\n");
				break;				
		}
	}
	printf("Programm is finished.\n");
	return 0;
}

char get_choice_(void) {
	int ch;
	printf("Enter letter, corresponding to choiced option:\n");
	printf("a. advice		b. bell\n");
	printf("c. counter		q. exit\n");
	ch = get_first_();
	while( ch != 'a' && ch != 'b' && ch != 'c' && ch != 'q') {
		printf("Please select 'a', 'b', 'c' or 'q'.\n");
		ch = get_first_();
	}
	return ch;
}

char get_first_(void) {
	int ch;
	
	ch = getchar();
	while(isspace(ch)) {
		ch = getchar();
		continue;	}
	while(getchar() != '\n') continue;
	return ch;
}
