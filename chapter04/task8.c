#include <stdio.h>
#include <string.h>
#define GALLON_IN_LITRES 3.785

int main(void) {
	const float MILE_IN_KM = 1.609;
	float miles;
	float gallons;
	
	printf("Enter miles: ");
	scanf("%f", &miles);
	printf("Enter gallons: ");
	scanf("%f", &gallons);
	printf("Fuel consumption(km/l): %.1f",
		(miles*MILE_IN_KM)/(gallons*GALLON_IN_LITRES));
		
	return 0;
}
