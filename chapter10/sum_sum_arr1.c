// сумма элементов массива
#include <stdio.h>
#define SIZE 10
int sum(int ar[], int n);
int sum_sum_arr1(void) {
	int marbles[] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;
	
	answer = sum(marbles, SIZE);
	printf("Total sum of elements array 'marbles' equals %ld.\n", answer);
	printf("Volume of memory, allocated for array 'marbles' consists of %zd byte(s).\n",
		sizeof marbles);
	return 0;
}

int sum(int ar[], int n) {
	int i;
	int total = 0;
	for(i=0; i < n; i++ )
		total +=ar[i];
	printf("Size 'ar' consists of %zd byte(s).\n", sizeof ar);
	
	return total;
}
