#include <stdio.h>
#define ROWS 3
#define COLS 5

void scanf_arr(double [], int);
void print_arr(double (*)[COLS]);
double average_of_set(double *, int);
double max_arr(double[][COLS]);

int task13(void) {
	double arr[ROWS][COLS]  = {
		{ 4.3, 4.3, 4.3, 3.0, 2.0 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1 }
	};
	
	int r;
	double sum=0.0;
	// наполнение массива
	/*for(r=0; r < ROWS; r++) {
		printf("Set #%d:\n", r+1);
		scanf_arr(arr[r], COLS);
	}*/
	
	// вывод массива
	print_arr(arr);
	
	// вычисляем среднее для каждого набора
	for(r=0; r < ROWS; r++) 
		printf("Average of set #%d: %g\n", r+1, average_of_set(arr[r], COLS));
	
	putchar('\n');
	
	// вычислить среднее всех значений
	for(r=0; r < ROWS; r++) 
		sum += average_of_set(arr[r], COLS);
	printf("Average of all numbers in array: %g\n", sum/ROWS);
	
	putchar('\n');
	
	// Наибольшее из всех значений
	printf("Max value of all numbers in array: %g\n", max_arr(arr));
	
	return 0;
}

void scanf_arr(double arr[], int n) {
	int i;
	
	for(i=0; i<n; i++) {
		printf("Enter %d element: ", i+1);
		scanf("%lf", &arr[i]);		
	}
}

void print_arr(double (*arr)[COLS]) {
	int r, c;
	
	printf("Original array:\n");
	for(r=0; r<ROWS; r++) {
		for(c=0; c<COLS; c++)
			printf("%5.2lf ", *(*(arr + r) + c));
		putchar('\n');
	}
	putchar('\n');
}

double average_of_set(double *arr, int n) {
	int r;
	double sum = 0.0;
	
	for(r=0; r<n; r++)
		sum += *(arr + r);
	return sum / n;
}

double max_arr(double arr[][COLS]) {
	int r, c;
	double max;
	
	for(r=0, max=**arr; r<ROWS; r++)
		for(c=0; c<COLS; c++)
			if(arr[r][c]>max) max = arr[r][c];
	return max; 
}
