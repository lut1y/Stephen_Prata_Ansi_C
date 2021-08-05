#include <stdio.h>
#include "task3.h"

void set_mode1(int *mode, int *prev_mode) {
	if(*mode>1) {
		printf("It's invalid mode. Used mode %s.\n",
			(*prev_mode == 1) ? "1 (american)" : "0 (metrical)");
		*mode = *prev_mode;
	}
	else
		*prev_mode = *mode;
}

void get_info1(int *mode, float *distance, float *fuel_consumption) {
	if(!(*mode)) { // метрический режим
		printf("Enter traveled distance in km: ");
		scanf("%f", distance);
		printf("Enter volume of fuel consumption in liters: ");
		scanf("%f", fuel_consumption);
	} else {
		printf("Enter traveled distance in miles: ");
		scanf("%f", distance);
		printf("Enter volume of fuel consumption in gallons: ");
		scanf("%f", fuel_consumption);
	}
}

void show_info1(int *mode, float *distance, float *fuel_consumption) {
	if(!(*mode)) 
		printf("Fuel consumption consist of %.2f liter(s) in 100 km.\n",
			(*fuel_consumption)/(*distance)*100);
	else
		printf("Fuel consumption consist of %.1f mile(s) in gallon.\n",
			(*distance)/(*fuel_consumption));
}

