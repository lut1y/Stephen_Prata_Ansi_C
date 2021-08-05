#include <stdio.h>
#include "pe12-2a.h"

void set_mode(int m) {
	if(m>1)
		printf("It's invalid mode. Used mode %s.\n",
			mode==1 ? "1 (american)" : "0 (metrical)");
	else
		mode = m;
}

void get_info(void) {
	if(!mode) { // метрический режим
		printf("Enter traveled distance in km: ");
		scanf("%f", &distance);
		printf("Enter volume of fuel consumption in liters: ");
		scanf("%f", &fuel_consumption);
	} else {
		printf("Enter traveled distance in miles: ");
		scanf("%f", &distance);
		printf("Enter volume of fuel consumption in gallons: ");
		scanf("%f", &fuel_consumption);
	}
}

void show_info(void) {
	if(!mode) 
		printf("Fuel consumption consist of %.2f liter(s) in 100 km.\n",
			fuel_consumption/distance*100);
	else
		printf("Fuel consumption consist of %.1f mile(s) in gallon.\n",
			distance/fuel_consumption);
}

