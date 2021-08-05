// исследование программы swap1.c
#include <stdio.h>

void interchange1(int u, int v);

int swap2(void) {
	int x = 5, y = 10;
	
	printf("Firstly x = %d and y = %d.\n", x, y);
	interchange1(x, y);
	printf("Now x = %d and y = %d.\n", x, y);
	
	return 0;
}

void interchange1(int u, int v) {
	int temp;
	
	printf("Firstly u = %d and v = %d.\n", u, v);
	temp = u;
	u = v;
	v = temp;
	printf("Now u = %d and v = %d.\n", u, v);
}
