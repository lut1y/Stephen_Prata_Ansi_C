#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LEN 10
#define SEATS 12

struct seat {
	short int id;
	bool reserved;
	char lname[LEN];
	char fname[LEN];
};

int getlet(const char *s);
int menu(void);
void show_free_seats(const struct seat *);
void update_field(char *, char *);
void show_list_free_seats(const struct seat *);
void show_list_free_seats(const struct seat *);

int task8(void) {
	struct seat seats[SEATS], *seat;
	int choice, size, i;
	FILE *fp;
	
	size = sizeof(struct seat);
	for(i=0; i<SEATS; i++) {
		seats[i].id = i + 1;
		seats[i].reserved = false;
	}
	if((fp = fopen("ticket.dat", "rb")) != NULL) {
		while(fread(seat, size, 1, fp) == 1) {
			seats[seat->id - 1].id = seat->id;
			seats[seat->id - 1].reserved = seat->reserved;
			update_field(seats[seat->id - 1].lname,  seat->lname);
			update_field(seats[seat->id - 1].fname, seat->fname);
			seat++;
		}
	}
	while((choice = menu()) != 'f') {
		
		switch(choice) {
			case 'a':
				show_free_seats(seats);
				break;
			case 'b':
				show_list_free_seats(seats);
				break;	
		}
		
	}
	
	puts("Program is finished.");
	return 0;
}

void show_list_free_seats(const struct seat *seat) {
	short int i, ct;
	
	printf("Free seats: ");
	for(i = 0, ct = 0; i < SEATS; seat++, i++) 
		if(seat->reserved == false) {
			printf("%hd, ", seat->id);
			ct++;
		}
	if(ct > 0) 
		printf("\b\b.\n");
	else puts("no free seats");
}

void update_field(char *field, char *newfield) {
	field = "";
	strcpy(field, newfield);
}

void show_free_seats(const struct seat *seat) {
	short int i, ct;
	
	for(i=0, ct = 0; i < SEATS; seat++, i++) 
		if(seat->reserved == false) ct++;
	printf("Count free seats: %hd.\n", ct);
}

int menu(void) {
	char ch;
	
	puts("For choicing function enter his letter: ");
	puts("a) Show count free seats");
	puts("b) Show list of free seats");
	puts("c) Show list of reserved seats in alphabet order");
	puts("d) To reserve seat for passager");
	puts("e) Remove reservation from seat");
	puts("f) Exit from program");
	printf("Choice: ");
	ch = getlet("abcdef");
	return ch;
}
