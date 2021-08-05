// пример вложенной структуры
#include <stdio.h>
#define LEN 20

const char *msgs[5] = {
	"   Thank you for a wonderful evening, ",
	"You have clearly demonstrated that ",
	"is a special type of man. We must definitely meet",
	"over a delicious dinner with ",
	" and have a fun"
};

struct name {
	char first[LEN];
	char last[LEN];
};

struct guy {
	struct name handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int friend(void) {
	
	struct guy fellow = {
		{"Billy", "Bons"},
		"backed lobster",
		"personal trainer",
		68112.00
	};
	
	printf("Dear %s, \n\n", fellow.handle.first);
	printf("%s%s.\n", msgs[0], fellow.handle.first);
	printf("%s%s\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2], fellow.job);
	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
	if(fellow.income > 150000.0)
		puts("!!");
	else if(fellow.income > 75000.0)
		puts("!");
	else
		puts(".");
	printf("\n%40s%s\n",  " ", "See you soon, ");
	printf("%40s%s\n", " ", "Sheila");
	
	return 0;
}

