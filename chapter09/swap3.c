// исследование указателей для обмена значениями переменных
#include <stdio.h>

void interchange2(int *u, int *v); // указатели на память

int swap3(void) {
	int x = 5, y = 10;
	
	printf("Firstly x = %d and y = %d.\n", x, y);
	interchange2(&x, &y); // передача адресов в функцию
	printf("Now x = %d and y = %d.\n", x, y);
	
	return 0;
}

void interchange2(int *u, int *v) {
	int temp;
	
	temp = *u;	// temp получает значение, на которое указывает u
	*u = *v;
	*v = temp;
}
