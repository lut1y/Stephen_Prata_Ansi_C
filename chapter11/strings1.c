#include <stdio.h>
#define MSG "I am symbol string constant."
#define MAXLENGTH 81

int strings1(void) {
	char words[MAXLENGTH] = "I am string, that store in array.";
	const char *pt1 = "Something indicate to me.";
	puts("Here are some strings:");
	// puts() - �������-�� ��������� ������ \n
	puts(MSG); // ����� � ���������
	puts(words); // ����� � �������
	puts(pt1); // ����� � ���������
	words[14] = 'f';
	puts(words);
	
	return 0;
}
