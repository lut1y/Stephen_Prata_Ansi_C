// ����������� � ���������� �����
#include <stdio.h>

int post_pre(void) {
	int a = 1, b = 1;
	int a_post, b_pre;
	
	a_post = a++; // �������� a++ �� ����� ����� ������������
	b_pre = ++b; // �������� ++b �� ����� ����� ������������
	
	printf("a  a_post   b   b_pre\n");
	printf("%1d %5d %5d %5d\n", a, a_post, b, b_pre);
	
	return 0;
}
