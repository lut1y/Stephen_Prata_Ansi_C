#include <stdio.h>

int for_geo(void) {
	double debt; 
	for(debt = 100.0; debt < 150.0; debt *= 1.1)
		printf("Now your indebtedness is $%.2f.\n", debt);
	return 0;
}
