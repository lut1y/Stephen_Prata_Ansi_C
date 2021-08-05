#include <stdio.h>
#define MONTHS 12
#define YEARS 5

float sum_prec_in_month(const float rain[][MONTHS], int n);
int task12(void) {
	const float rain[YEARS][MONTHS] =
	{
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
	};
	float total;
	
	total = sum_prec_in_month(rain, YEARS);
	printf("The average annual rainfall is %.1f inches.\n\n",
		total/YEARS);
	average_annual_rainfall(rain, YEARS);
	printf("\n");	
		
	return 0;
}

float sum_prec_in_month(const float rain[][MONTHS], int n) {
	int month, year;
	float subtot, total; 
	
	printf(" YEAR	AMOUNT PRECIPITATION (in inches)\n");
	for(year=0, total = 0; year < n; year++) {
		for(month=0, subtot=0; month < MONTHS; month++)
			subtot += rain[month][year];
		printf("%5d\t%15.1f\n", 2010 + year, subtot);
		total += subtot;
	}
	return total;
}

void average_annual_rainfall(const float rain[][MONTHS], int n) {
	int month, year;
	float subtot;
	
	printf("THE AVERAGE MONTHLY RAINFALL:\n\n");
	printf("Jan   Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
	for(month=0; month < MONTHS; month++) {
		// для каждого месяца суммировать количество осадков на протяжении годов
		for(year = 0, subtot = 0; year < n; year++)
			subtot += rain[year][month];
		printf("%4.1f ", subtot/YEARS);
	}
}

