#include <stdio.h>

void copy_arr(double [], const double [], int);
void copy_ptr(double *, const double *, int);
void copy_ptrs(double *, const double *, int *);


int task2(void) {
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };	
	double target1[5];
	double target2[5];
	double target3[5];
	
	printf("Source : ");
	print_array(source, 5);
		
	copy_arr(target1, source, 5);
	printf("Target1: ");
	print_array(target1, 5);
	
	copy_ptr(target2, source, 5);
	printf("Target2: ");
	print_array(target2, 5);
	
	copy_ptrs(target3, source, source + 5);
	printf("Target3: ");
	print_array(target2, 5);
		
	return 0;
}

void copy_arr(double target[], const double source[], int n) {
	int index;
	
	for(index = 0; index < 5; index++)
		target[index] = source[index];
}

void copy_ptr(double *target, const double *source, int n) {
	int index = 0;
	
	while(index++ < 5)
		*target++ = *source++;	
}

void copy_ptrs(double *target, const double *source, int *end) {
	while(source < end) 
		*target++ = *source++;				
}

// выводит содержимое массива
void print_array(const double a[], int n) {
	int i;
	
	for(i=0; i<n; i++)
		printf("%g ", a[i]);
	putchar('\n');
}
