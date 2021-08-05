#include <stdio.h>
#include <stdbool.h>

bool find_num(int *sort_array, int len, int num);

int task6(void) {
	
	int arr[] = { 1, 2, 3, 4, 5, 8, 27, 64, 125 };
	int len = sizeof(arr) / sizeof(int);
	int i;
	
	printf("In array arr:\n");
	for(i=0; i<len; i++) 
		printf("%d ", arr[i]);
	putchar('\n');
	i = 26;
	printf("Number \"%d\" is ", i);
	if(find_num(arr, len, i))
		printf("attend\n");
	else
		printf("absent\n");
	
	return 0;
}

bool find_num(int *sort_array, int len, int num) {
	int min = 0;
	int max = len - 1;
	int mid;
	bool found = false;
	
	while(min <= max) {
		mid = (min + max) / 2;
		if(num < sort_array[mid])
			max = mid - 1;
		else if(num > sort_array[mid])
			min = mid + 1;
		else {
			found = true;
			break;
		}	
	}
	return found;	
}
