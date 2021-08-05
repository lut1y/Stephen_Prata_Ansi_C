// использование условной операции
#include <stdio.h>
#define COVERAGE 350	// число квадратных фунтов на одну банку краски

int paint(void) {
	int sq_feet;
	int cans;
	
	printf("Enter count square feets, that need to paint:\n");
	while(scanf("%d", &sq_feet) == 1) {
		cans = sq_feet / COVERAGE;
		cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
		printf("For this required %d %s of paint.\n",
			cans, cans == 1 ? "bank" : "banks");
		printf("Enter next value (or q for finishing):\n");
	}
	
	return 0;
}
