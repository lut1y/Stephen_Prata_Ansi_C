#include <stdio.h>
#define ROWS 3
#define COLS 5

void print_array_2d(double ar[ROWS][COLS]);
void array_x_2(double ar[ROWS][COLS]);

int task11(void) {
	double ar[ROWS][COLS]  = {
		{ 4.3, 4.3, 4.3, 3.0, 2.0 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1 }
	};
	print_array_2d(ar);
	array_x_2(ar);
	print_array_2d(ar);
	
	
	return 0;
}

void print_array_2d(double ar[ROWS][COLS]) {
	int r, c;
	
	for(r=0; r<ROWS; r++) {
		for(c=0; c<COLS; c++)
			printf("%5.2lf ", ar[r][c]);
		putchar('\n');
	}
	putchar('\n');
}

void array_x_2(double ar[ROWS][COLS]) {
	int r, c;
	
	for(r=0; r<ROWS; r++) 
		for(c=0; c<COLS; c++)
			ar[r][c] *= 2;
}
