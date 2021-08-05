// экспоненциальный рост
#include <stdio.h>
#define SQUARES 64 // количество клеток шахматной доски

int wheat(void) {
	const double CROP = 2E16; // мировой урожай пшеницы в зернах
	double current, total;
	
	int count = 1;
	printf("square     added        total    ");
	printf("percent from \n");
	printf("           wheat        wheat    ");
	printf("world harvest\n");
		total = current = 1.0; // начинаем с одного зернышка
	printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total/CROP);
	while(count < SQUARES) {
		count = count + 1;
		current = 2.0 * current;
		// удваиваем количество зерен на следующей клетке
		total += current;
		printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total/CROP);
	}
	printf("That's all.");
	
	return 0;
}
