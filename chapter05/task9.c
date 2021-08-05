#include <stdio.h>

void Temperatures(double temper_F);

int task9(void) {
	double temperature_F;
	
	printf("Temperature of Fahrenheit: ");
	while(1 == scanf("%lf", &temperature_F)) {
		Temperatures(temperature_F);
		printf("Enter temperature of Fahrenheit ('q' for exit): ");
	}
		
	printf("\nReady");	
	return 0;
}

void Temperatures(double temper_F) {
	const double koef_Celsius1 = 5.0/9.0;
	const float koef_Celsius2 = 32.0;
	const float koef_Kelvin = 273.16;
	
	double temper_C = koef_Celsius1 * (temper_F - koef_Celsius2);
	double temper_K = temper_C + koef_Kelvin;
	printf("%.2lfF %.2lfC %.2lfK\n", temper_F, temper_C, temper_K);
	
}
