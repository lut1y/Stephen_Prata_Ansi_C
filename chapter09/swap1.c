// первая попытка создания функции обмена значениями
#include <stdio.h>

void interchange(int u, int v);

int swap1(void) {
	int x = 5, y = 10;
	
	printf("Firstly x = %d and y = %d.\n", x, y);
	interchange(x, y);
	printf("Now x = %d and y = %d.\n", x, y);
	
	return 0;
}

void interchange(int u, int v) {
	int temp;
	
	temp = u;
	u = v;
	v = temp;
}
