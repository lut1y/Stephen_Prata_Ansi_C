#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define NUM 100

void init(int *, int);
void gen(int *, int);

int task6(void) {
	int i,
		arr[SIZE];
	
	init(arr, SIZE);
	srand((unsigned int) time(0));
	gen(arr, SIZE);
	
	for(i=0; i < SIZE; i++) {
		printf("%d: %d\n", i+1, arr[i]);
	}	
	putchar('\n');
	
	printf("Program is finished.\n");
	return 0;
}

void init(int *arr, int size) {
	int i;
	
	for(i=0; i < size; i++)
		arr[i] = 0;
}

void gen(int *arr, int size) {
	int i, num;
	
	
	for(i=0; i < NUM; i++) {
		num = rand() % 10 + 1;
		arr[num-1]++;
	}
}
