#include <stdio.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int task8(void) {
	int *pa;
	int size;
	int value;
	
	printf("Enter count elements: ");
	while(scanf("%d", &size) == 1 && size > 0) {
		printf("Enter value for initialization: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if(pa) {
			show_array(pa, size);
			free(pa);
		}
		printf("Enter count elements (<1 for finishing): ");
	}
	printf("Program is finished.\n");
	
	return 0;
}

int * make_array(int elem, int val) {
	int *ptr,
		i;
	
	ptr = (int *) malloc(elem * sizeof(int));
	for(i = 0; i < elem; i++) 
		ptr[i] = val;
	return ptr;
}

void show_array(const int ar[], int n) {
	int i;
	
	for(i=0; i < n; i++) {
		printf("%3d", ar[i]);
		if(i % 5 == 4) putchar('\n');
	}
	if(i % 5 != 0) putchar('\n');
}
