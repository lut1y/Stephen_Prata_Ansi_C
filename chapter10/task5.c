#include <stdio.h>

double diff_min_max(double *, int);
int task5(void) {
	double arr[] = { 20.0, 10.5, 5.1, 39.4 , 4.8, 16.1, 19.7, 26.0, 31, 20 };
	printf("Max value - min value = %g", diff_min_max(arr, 10));
	
	return 0;
}

double diff_min_max(double *ar, int n) {
	double min, max;
	int i;
	
	for(min = max = *ar++, i = 1; i < n; i++, ar++) {
		if(min > *ar) min = *ar;
		if(max < *ar) max = *ar;
	}
	printf("min = %g, max = %g\n", min, max);
	return max - min;
}
