#include <stdio.h>
#include <string.h>
#define LEN 10

struct FIO {
	char fname[LEN];
	char sname[LEN];
	char lname[LEN];
};

struct card_soc_ins {
	long int id;
	struct FIO name;
};

void print(struct card_soc_ins card);
void print1(struct card_soc_ins *card);

int task4(void) {
	struct card_soc_ins cards[5] = {
		{
			302093823,
			{ "Flossie", "M", "Dribble"	}
		},
		{
			302193826,
			{ "Ivan", "Ivanovich", "Ivanov" }
		},
		{
			303098831,
			{ "Petr", "Fedorovich", "Petrov" }
		},
		{
			379193862,
			{ "Nikita", "Andreevich", "Ivlev" }
		},
		{
			345998844,
			{ "Alex", "", "Fitness" }
		}
	};
	int i;
	
	for(i = 0; i < 5; i++) {
		printf("%p: ", &cards[i]);
//		print(cards[i]);
		print1(&cards[i]);	
	}
	
	puts("Program is finished.");
	return 0;
}

void print(struct card_soc_ins card) {
	printf("%s, %s", 
			card.name.lname,
			card.name.fname);
		if(strlen(card.name.sname) != 0)
			printf(" %c.", card.name.sname[0], card.id);
		printf(" -- %ld", card.id);
		printf(" (%p)\n", &card);
}
void print1(struct card_soc_ins *card) {
	printf("%s, %s", 
			card->name.lname,
			card->name.fname);
		if(strlen(card->name.sname) != 0)
			printf(" %c.", card->name.sname[0], card->id);
		printf(" -- %ld", card->id);
		printf(" (%p)\n", card);
}
