#include <stdio.h>
#define ROWS 3
#define COLS 5

void copy_array_float_len(int row, int col, 
			const double ar[row][col], double ar1[row][col]);
void print_arr_2d(int row, int col, double ar[row][col]);

int task9(void) {
	double ar[ROWS][COLS]  = {
		{ 4.3, 4.3, 4.3, 3.0, 2.0 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1 }
	};
	double ar1[ROWS][COLS];	
	
	copy_array_float_len(ROWS, COLS, ar, ar1);
	
	print_arr_2d(ROWS, COLS, ar);
	print_arr_2d(ROWS, COLS, ar1);
		
	return 0;
}

void copy_array_float_len(int row, int col, 
			const double ar[row][col], double ar1[row][col]) {
	int r, c;
	
	for(r=0; r<row; r++)
		for(c=0; c<col; c++)
			ar1[r][c] = ar[r][c];
}

void print_arr_2d(int row, int col, double ar[row][col]) {
	int r, c;
	
	for(r=0; r<row; r++) {
		for(c=0; c<col; c++)
			printf("%4.2lf ", ar[r][c]);
		putchar('\n');
	}
	putchar('\n');
}
