// ����� ��������� �������
#include <stdio.h>
#define SIZE 10

int sump(int *start, int *end);

int sum_arr2(void) {
	int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;
	
	printf("marbles = %p\n", marbles);
	answer = sump(marbles, marbles + SIZE); // �������� ����� ������ ������� � ����� ������ + 4
	
	printf("Total sum of elements array 'marbles' equals %ld.\n", answer);
	
	return 0;
}

// ������������� ���������� ����������
int sump( int *start, int *end) { // * - ���� ��������, ���������� � ������
	int total;
	
	while(start < end) {
		printf("start = %d\n", *start);
		total += *start;
		start++; // ����� ����������� �� int
	}
	
	return total;
}
