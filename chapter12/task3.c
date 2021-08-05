// компилировать вместе с pe12-2a.c
#include <stdio.h>
#include "task3.h"

int task3(void) {
	int mode,
		prev_mode = 0;
	float distance,
		  fuel_consumption;	
		
	printf("Enter 0 for metrical mode or 1 for american mode: ");
	scanf("%d", &mode);
	while(mode >= 0) {
		set_mode1(&mode, &prev_mode);
		get_info1(&mode, &distance, &fuel_consumption);
		show_info1(&mode, &distance, &fuel_consumption);
		printf("Enter 0 for metrical mode or 1 for american mode");
		printf(" [-1 for exit]: ");
		scanf("%d", &mode);
	}
	printf("Program is finished.\n");
	return 0;	
}


