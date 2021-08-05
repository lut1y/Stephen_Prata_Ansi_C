#include <stdio.h>

void scanf_arr1(int cols, double *);
void print_arr1(int rows, int cols, double ar[rows][cols]);
double average_of_set1(int cols, double *);
double max_arr1(int rows, int cols, double ar[rows][cols]);

int task14(void) {
	int r,
		rows = 2,
		cols = 2;
	double sum = 0.0;
	
	double arr[rows][cols]/* = {
		{ 4.3, 4.3, 4.3, 3.0, 2.0 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1 }
	}*/;
	
	
	// наполнение массива
	for(r=0; r < rows; r++) {
		printf("Set #%d:\n", r+1);
		scanf_arr1(cols, arr[r]);
	}
	
	putchar('\n');
	
	// вывод массива
	print_arr1(rows, cols, arr);
	
	// вычисляем среднее для каждого набора
	for(r=0; r < rows; r++) 
		printf("Average of set #%d: %g\n", r+1, average_of_set1(cols, arr[r]));
	
	putchar('\n');
	
	// вычислить среднее всех значений
	for(r=0; r < rows; r++) 
		sum += average_of_set1(cols, arr[r]);
	printf("Average of all numbers in array: %g\n", sum/rows);
	
	putchar('\n');
	
	// Наибольшее из всех значений
	printf("Max value of all numbers in array: %g\n", max_arr1(rows, cols, arr));
	
	return 0;
}

void scanf_arr1(int cols, double ar[cols]) {
	int i;
	
	for(i=0; i<cols; i++) {
		printf("Enter %d element: ", i+1);
		scanf("%lf", &ar[i]);		
	}
}

void print_arr1(int rows, int cols, double ar[rows][cols]) {
	int r, c;
	
	printf("Original array:\n");
	for(r=0; r<rows; r++) {
		for(c=0; c<cols; c++)
			printf("%5.2lf ", *(*(ar + r) + c));
		putchar('\n');
	}
	putchar('\n');
}

double average_of_set1(int cols, double ar[cols]) {
	int r;
	double sum = 0.0;
	
	for(r=0; r < cols; r++)
		sum += *(ar + r);
	return sum / cols;
}

double max_arr1(int rows, int cols, double ar[rows][cols]) {
	int r, c;
	double max;
	
	for(r=0, max=**ar; r<rows; r++)
		for(c=0; c<cols; c++)
			if(ar[r][c]>max) max = ar[r][c];
	return max; 
}
