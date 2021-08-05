// бросание можества костей
#include <stdio.h>
#include <stdlib.h>		// для библиотечной функции srand()
#include <time.h>		// для функции time()
#include "diceroll.h"	// для функции roll_n_dice()
						// и для переменной roll_count

int task7(void) {
	int dices, roll, i;
	int sides;
	int status;
	int draw;
	
	srand((unsigned int) time(0));		// рандомизация начального числа
	
	printf("Enter count of draws or 'q' for finishing: ");
	while(scanf("%d", &draw) == 1 && draw > 0) {
		printf("How much sides and dices? ");
		scanf("%d %d", &sides, &dices);
		printf("We have %d draws %d dices with %d sides.\n",
			draw, dices, sides);
		for(i=0; i<draw; i++) {
			printf("%d  ", roll_n_dice(dices, sides));
			if(i % 15 == 14) putchar('\n');
		}
		if(i % 15 != 0) putchar('\n');
		printf("Enter count of draws or 'q' for finishing: ");
	}
	
	printf("Be happy!\n");
}
