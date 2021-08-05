// технология меню
#include <stdio.h>

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int menuette(void) {
	int choice;
	void count(void);
	while( (choice = get_choice()) != 'q') {
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

void count(void) {
	int n, i;
	printf("To what limit should one count? Enter integer number:\n");
	n = get_int();
	for(i=1; i<=n; i++)
		printf("%d\n", i);
	while(getchar() != '\n') continue;
}

char get_choice(void) {
	int ch;
	printf("Enter letter, corresponding to choiced option:\n");
	printf("a. advice		b. bell\n");
	printf("c. counter		q. exit\n");
	ch = get_first();
	while( ch != 'a' && ch != 'b' && ch != 'c' && ch != 'q') {
		printf("Please select 'a', 'b', 'c' or 'q'.\n");
		ch = get_first();
	}
	return ch;
}

char get_first(void) {
	int ch;
	ch = getchar();
	while(getchar() != '\n') continue;
	return ch;
}

int get_int(void) {
	int input;
	char ch;
	while(scanf("%d", &input) != 1) {
		while( (ch = getchar()) != '\n')
			putchar(ch); // отбросить неправильный ввод
		printf(" is not integer.\nEnter ");
		printf("integer, as 25, -178 or 3: ");
	}
	return input;
}
