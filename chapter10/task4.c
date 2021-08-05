#include <stdio.h>

int max_index(int [], int);

int task4(void) {
	int arr[] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	
	printf("Index of max value: %d", max_index(arr, 10));
	return 0;
}

int max_index(int a[], int n) {
	int max, i;
	
	for(i = 1, max = 0; i < n; i++)
		if(a[max] < a[i]) max = i;	
	return max;
}
