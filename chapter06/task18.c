#include <stdio.h>

int task18(void) {
	int friend = 5;
	int week = 1;
	
	printf("week friend\n");
	while(friend < 150) {
		friend = (friend - week) * 2;
		printf("%4d %6d\n", week, friend);		
		week++;		
	}
	
	return 0;
}
