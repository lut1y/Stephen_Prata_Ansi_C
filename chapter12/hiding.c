// ���������� � ������
#include <stdio.h>

int hiding(void) {
	
	int x = 30;	// �������� ����������
	
	printf("'x' in output block: %d in address %p\n", x, &x);
	{
		int x = 77;	// ����� ���������� x, ���������� ������ x
		printf(" 'x' in input block: %d in address %p\n", x, &x);
	}
	printf("'x' in output block: %d in address %p\n", x, &x);
	while(x++ < 33) { // �������� ���������� x
		int x = 100;
		x++;
		printf("'x' in cycle while: %d in address %p\n", x, &x);
	}
	printf("'x' in output block: %d in address %p\n", x, &x);
	
	return 0;	
}
