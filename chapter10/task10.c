#include <stdio.h>

void sum_ar3(const int*, const int*, int*);

int task10(void) {
	int a[4] = { 2, 4, 5, 8 };
	int b[4] = { 1, 0, 4, 6 };
	int c[4], i;
	
	sum_ar3(a, b, c);
	
	for(i = 0; i < 4; i++)
		printf("%d ", *(c + i));
	
	return 0;
}

void sum_ar3(const int *ar1, const int *ar2, int *ar) {
	int i;
	
	for(i=0; i < 4; i++)
		*ar++ = *ar1++ + *ar2++;
}
