// ������ ��������� �� ��� ������� ������, �������� �������
#include <stdio.h>
#define SPACE ' ' // �������, ������, �������

int cypher1(void) {
	char ch;
	
	while((ch = getchar()) != '\n') {
		if(ch == SPACE)
			putchar(ch);
		else
			putchar(ch + 1);
	}
	putchar(ch);
	
	return 0;
}
