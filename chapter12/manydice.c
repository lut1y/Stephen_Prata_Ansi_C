// �������� �������� ������
#include <stdio.h>
#include <stdlib.h>		// ��� ������������ ������� srand()
#include <time.h>		// ��� ������� time()
#include "diceroll.h"	// ��� ������� roll_n_dice()
						// � ��� ���������� roll_count

int manydice(void) {
	int dice, roll;
	int sides;
	int status;
	
	srand((unsigned int) time(0));		// ������������ ���������� �����
	printf("Enter count side of dice or 0 for finishing program.\n");
	while(scanf("%d", &sides) == 1 && sides > 0) {
		printf("How much is dice?\n");
		if ((status = scanf("%d", &dice)) != 1) {
			if(status == EOF)
				break;		// ����� �� �����
			else {
				printf("You must enter integer number.");
				printf(" Let's start from start.\n");
				while(getchar() != '\n') continue;
				printf("How much is dice? For finishing press 0.\n");
				continue;	// ����� �������� �����
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You draw %d one(s), used %d dices with %d sides.\n",
			roll, dice, sides);
		printf("How much is dice? For finishing enter 0.\n");
	}
	printf("Function rollem() was called %d one(s).\n",
			roll_count);	// ������������ ���������� extern
	printf("Be happy!\n");
}
