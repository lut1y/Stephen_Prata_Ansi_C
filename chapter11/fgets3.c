// ������������� ������� fgets()
#include <stdio.h>
#define STLEN 10

int fgets3(void) {
	char words[STLEN];
	int i;
	puts("Enter string (or empty string for exit from program): ");
	while(fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
		i=0;
		// fgets ��������� STLEN-1 �������� ������ + \0, ����
		// ���� �������� ������ STLEN-1
		while(words[i] != '\n' && words[i] != '\0')
			i++;
		if(words[i] == '\n')
			words[i] = '\0';
		else
			// ����� ���� �� ����� �������������� ������
			// "���������" ���������� �������
			while(getchar() != '\n')
				continue;
		puts(words);
	}
	puts("Ready.");
	return 0;
}
