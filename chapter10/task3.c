#include <stdio.h>

int max_val(int *, int);

int task3(void) {
	int arr[] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	
	printf("Max value: %d", max_val(arr, 10));
	return 0;
}

int max_val(int *ar, int n) {
	int max, i;
	
	for(max = *ar++, i=1; i < n; i++, ar++) 
		if(*ar > max) 
			max = *ar;
	
	return max;
}
