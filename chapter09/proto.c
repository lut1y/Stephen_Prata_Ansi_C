// ���������� ��������� �������
#include <stdio.h>
int imax1(int, int);		/* ���������� � ������ ����� */

int proto(void) {
//	������ �������������� ������ � ��������� � ���-�� ����������
//	printf("Higher value from  %d and %d is %d.\n",
//		3, 5, imax1(3));
	printf("Higher value from %d and %d is %d.\n",
		3, 5, imax1(3.0, 5.0));	
	return 0;
}

int imax1(int n, int m)
{
	return (n > m ? n : m);
}
