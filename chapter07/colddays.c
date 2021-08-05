// вычисляет процент случает, когда температура опускается ниже нуля
#include <stdio.h>

int colddays(void) {
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;
	
	printf("Enter list of min day temperature.\n");
	printf("Use scale of Celsius; for finishing press 'q'\n");
	while(scanf("%f", &temperature) == 1) {
		all_days++;
		if(temperature < FREEZING) cold_days++;
	}
	
	if(all_days != 0)
		printf("%d - common count days: %.lf%% with temperature below zero.\n",
			all_days, 100*(float) cold_days / all_days);
	else
		printf("Data not entered!\n");
		
	return 0;
}
