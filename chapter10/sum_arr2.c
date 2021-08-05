// сумма элементов массива
#include <stdio.h>
#define SIZE 10

int sump(int *start, int *end);

int sum_arr2(void) {
	int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;
	
	printf("marbles = %p\n", marbles);
	answer = sump(marbles, marbles + SIZE); // передаем адрес начала массива и адрес начала + 4
	
	printf("Total sum of elements array 'marbles' equals %ld.\n", answer);
	
	return 0;
}

// использование арифметики указателей
int sump( int *start, int *end) { // * - дает значение, хран€щеес€ в €чейке
	int total;
	
	while(start < end) {
		printf("start = %d\n", *start);
		total += *start;
		start++; // адрес увеличиваем на int
	}
	
	return total;
}
