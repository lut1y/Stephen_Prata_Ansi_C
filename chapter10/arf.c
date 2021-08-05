// функции, манипулирующие с массивами
#include <stdio.h>
#define SIZE 5
void show_array(const double a[], int n);
void mult_array(double ar[], int n, double mult);
int arf(void) {
	double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
	
	printf("Basic array dip:\n");
	show_array(dip, SIZE);
	mult_array(dip, SIZE, 2.5);
	printf("Array 'dip' after call function mult_array():\n");
	show_array(dip, SIZE);
	
	return 0;
}

// выводит содержимое массива
void show_array(const double a[], int n) {
	int i;
	
	for(i=0; i<n; i++)
		printf("%8.3f ", a[i]);
	putchar('\n');
}

// умножает каждый элемент массива на один и тот же множитель
void mult_array(double ar[], int n, double mult) {
	int i;
	for(i=0; i<n; i++)
		ar[i] *= mult;
}
