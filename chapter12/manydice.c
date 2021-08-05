// бросание можества костей
#include <stdio.h>
#include <stdlib.h>		// для библиотечной функции srand()
#include <time.h>		// для функции time()
#include "diceroll.h"	// для функции roll_n_dice()
						// и для переменной roll_count

int manydice(void) {
	int dice, roll;
	int sides;
	int status;
	
	srand((unsigned int) time(0));		// рандомизация начального числа
	printf("Enter count side of dice or 0 for finishing program.\n");
	while(scanf("%d", &sides) == 1 && sides > 0) {
		printf("How much is dice?\n");
		if ((status = scanf("%d", &dice)) != 1) {
			if(status == EOF)
				break;		// выход из цикла
			else {
				printf("You must enter integer number.");
				printf(" Let's start from start.\n");
				while(getchar() != '\n') continue;
				printf("How much is dice? For finishing press 0.\n");
				continue;	// новая итерация цикла
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You draw %d one(s), used %d dices with %d sides.\n",
			roll, dice, sides);
		printf("How much is dice? For finishing enter 0.\n");
	}
	printf("Function rollem() was called %d one(s).\n",
			roll_count);	// используется переменная extern
	printf("Be happy!\n");
}
