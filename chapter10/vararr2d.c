// функции, использующие массивы переменной длины
#include <stdio.h>
#define ROWS 3
#define COLS 4
int sum2d1(int rows, int cols, int ar[rows][cols]);
int vararr2d(void) {
	int i, j;
	int rs = 3;
	int cs = 10;
	int junk[ROWS][COLS] = {
		{ 2, 4, 6, 8},
		{ 3, 5, 7, 9},
		{ 12, 10, 8, 6}
	};
	int morejunk[ROWS-1][COLS+2] = {
		{ 20, 30, 40, 50, 60, 70},
		{ 5, 6, 7, 8, 9, 10}
	};
	int varr[rs][cs];	// массив переменной длины
	for(i = 0; i < rs; i++)
		for(j = 0; j < cs; j++)
			varr[i][j] = i*j + j;
	printf("Tradiotional array 3x5\n");
	printf("Sum of all elements = %d\n", sum2d1(ROWS, COLS, junk));
	printf("Tradiotional array 2x6\n");
	printf("Sum of all elements = %d\n", sum2d1(ROWS-1, COLS+2, morejunk));
	printf("Array float length 3x10\n");
	printf("Sum of all elements = %d\n", sum2d1(rs, cs, varr));
	return 0;
}

// функции с параметром типа массива переменной длины
int sum2d1(int rows, int cols, int ar[rows][cols]) {
	int r, c, tot = 0;
	
	for(r = 0; r < rows; r++)
		for(c = 0; c < cols; c++)
			tot +=ar[r][c];
	return tot;	
}
