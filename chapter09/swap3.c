// ������������ ���������� ��� ������ ���������� ����������
#include <stdio.h>

void interchange2(int *u, int *v); // ��������� �� ������

int swap3(void) {
	int x = 5, y = 10;
	
	printf("Firstly x = %d and y = %d.\n", x, y);
	interchange2(&x, &y); // �������� ������� � �������
	printf("Now x = %d and y = %d.\n", x, y);
	
	return 0;
}

void interchange2(int *u, int *v) {
	int temp;
	
	temp = *u;	// temp �������� ��������, �� ������� ��������� u
	*u = *v;
	*v = temp;
}
