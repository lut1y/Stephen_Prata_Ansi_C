// использование указателя на структуру
#include <stdio.h>
#define LEN 20

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

int friends(void) {
	
	struct guy fellow[2] = {
		{
			{"Billy", "Bons"},
			"backed lobster",
			"personal trainer",
			68112.00
		},
		{
			{"Jim", "Hokins"},
			"fish fricassee",
			"editor of tabloid",
			68112.00
		}
	};
	
	struct guy *him; /* указатель на структуру */
	
	printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
	him = &fellow[0];
	printf("pointer #1: %p #2: %p\n", him, him+1);
	printf("him->income equals $%.2f: (*him).income equals $%.2f\n",
			him->income, (*him).income);
	him++;
	printf("him->favfood equals %s: him->handle.last equals %s\n",
			him->favfood, him->handle.last);
	
	return 0;
}

