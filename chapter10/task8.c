#include <stdio.h>

void copy_ptrs(double *, const double *, int *);

int task8(void) {
	double arr7[] = { 20.0, 10.5, 5.1, 39.4, 4.8, 16.1, 19.7 };
	double arr3[3];
	
	print_array(arr7, 7);
	copy_ptrs(arr3, arr7 + 2, arr7 + 5);
	print_array(arr3, 3);
	
	
	return 0;
}
