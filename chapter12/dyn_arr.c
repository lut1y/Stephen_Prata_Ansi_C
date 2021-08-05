// динамически выделяемый массив
#include <stdio.h>
#include <stdlib.h> /* для malloc(), free() */

int dyn_arr(void) {
	double *ptd;
	int max = 0;
	int number;
	int i = 0;
	
	puts("Enter maximally count of elements type of 'double'.");
	if(scanf("%d", &max) != 1) {
		puts("Count entered invalid -- program is finished.");
		exit(EXIT_FAILURE);
	}
	ptd = (double *) malloc(max * sizeof(double));
	if(ptd == NULL) {
		puts("Can't allocate memory. Program is finished.");
		exit(EXIT_FAILURE);
	}
	/* ptd теперь указывает на массив из max элементов */
	puts("Enter values (q for exit): ");
	while(i < max && scanf("%lf", &ptd[i]) == 1)
		++i;
	printf("Entered %d elements:\n", number = i);
	for(i = 0; i < number; i++) {
		printf("%7.2f ", ptd[i]);
		if(i % 7 == 6) putchar('\n');
	}
	if(i % 7 != 0) putchar('\n');
	puts("Program is finished.");
	free(ptd);
	
	return 0;
}
