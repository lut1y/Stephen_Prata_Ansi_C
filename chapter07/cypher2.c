// ������ �������� ������, �������� ����������� �������,
// ������� �� �������� �������
#include <stdio.h>
#include <ctype.h>	// ��� ������� � isalpha()

int cypher2(void) {
	char ch;
	
	while((ch = getchar()) != '\n') {
		if(isalpha(ch))
			putchar(ch+1);
		else
			putchar(ch);
	}
	putchar(ch);
	
	return 0;
}
