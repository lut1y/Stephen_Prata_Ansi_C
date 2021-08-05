#include <stdio.h>
#include <stdlib.h>

void print(const int array[], int limit);
void sort(int array[], int limit);

#define SIZE 100

int task5(void) {
	int i;
	int arr[SIZE];
	
	for(i=0; i<SIZE; i++) 
		arr[i] = rand() % 10 + 1;
	puts("initial array");
	print(arr, SIZE);
	sort(arr, SIZE);
	puts("\nsorted array");
	print(arr, SIZE);
	printf("\n");
	
	return 0;
}

void sort(int array[], int limit) {
	int i, j, temp;
	
	for(i=0; i < limit-1; i++)
		for(j=i + 1; j < limit; j++) 
			if(array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;		
			}		
}

void print(const int array[], int limit) {
	int i;
	
	for(i=0; i<SIZE; i++) {
		printf("%2d ", array[i]);
		if(i % 10 == 9) putchar('\n');
	}
	if(i % 10 != 0) putchar('\n');
}
