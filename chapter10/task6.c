#include <stdio.h>

void reverse(double [], int);
void print_array(const double a[], int n);

int task6(void) {
	double arr[] = { 20.0, 10.5, 5.1, 39.4 , 4.8, 16.1, 19.7, 26.0, 31, 20 };
	
	print_array(arr, 10);
//	putchar('\n');	
	reverse(arr, 10);
//	putchar('\n');
	print_array(arr, 10);	
		
	return 0;
}

void reverse(double a[], int n) {
	double temp;
	int i;
	
	for(i = 0; i < n/2; i++) {
		temp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = temp;
	}
}
