// компилировать вместе с pe12-2a.c
#include <stdio.h>
#include "pe12-2a.h"

int task2(void) {
	int mode;
	printf("Enter 0 for metrical mode or 1 for american mode: ");
	scanf("%d", &mode);
	while(mode >= 0) {
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metrical mode or 1 for american mode");
		printf(" [-1 for exit]: ");
		scanf("%d", &mode);
	}
	printf("Program is finished.\n");
	return 0;	
}

