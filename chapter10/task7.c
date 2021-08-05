#include <stdio.h>
#define ROWS 2
#define COLS 5

void copy_arr(double [], const double [], int);
void copy_ptr(double *, const double *, int);
void copy_ptrs(double *, const double *, int *);


int task7(void) {
	double ar[ROWS][COLS]  = {
		{ 4.3, 4.3, 4.3, 3.0, 2.0 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4 }
	};
	double ar1[ROWS][COLS];
	int i;
	
	for(i=0; i<ROWS; i++) {
		copy_ptr(ar1[i], ar[i], COLS);
	}
	
	for(i=0; i<ROWS; i++) {
		print_array(ar1[i], COLS);
	}
	
	return 0;
}
