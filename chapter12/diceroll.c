// эмул€ци€ игры в кости
#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>	// дл€ библиотечной функции rand()

int roll_count = 0;	// внешнее св€зывание

static int rollem(int sides) { // закрыта€ дл€ этого файла
	int roll;
	
	roll = rand() % sides + 1;
	++roll_count;	// подсчет вызовов функции
	
	return roll;
}

int roll_n_dice(int dice, int sides) {
	int d;
	int total = 0;
	
	if(sides < 2) {
		printf("Required minimum 2 sides.\n");
		return -2;
	}
	if(dice < 1) {
		printf("Required minimum 1 dice.\n");
		return -1;
	}
	
	for(d=0; d < dice; d++)
		total += rollem(sides);
	return total;	
}
