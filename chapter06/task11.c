#include <stdio.h>
#define SIZE 5

int task11(void) {
	int i, a[SIZE];
	
	printf("Enter %d elements of array: \n", SIZE);
	for(i=0; i < SIZE; i++)
		scanf("%d", &a[i]);
	
	printf("Reverse order: ");
	for(i=SIZE-1; i>=0; i--)
		printf("%4d", a[i]);
	printf("\nFINISH!"); 
}
