// ���������� ������� ��������, ���� � �����
#include <stdio.h>
#include <ctype.h> // ��� isspace()
#include <stdbool.h> // ��� bool, true, false
#define STOP '|'

int wordcnt(void) {
	char c;				 // ����������� ������
	char prev;  		 // ���������� ����������� ������
	long n_chars = 0L;	 // ���������� ��������	
	int n_lines = 0;	 // ���������� �����
	int n_words = 0;	 // ���������� ����
	int p_lines = 0;	 // ���������� �������� �����
	bool inword = false; //  == true ���� ������ � ��������� ������ �����
	
	printf("Enter text for analisys (| for finishing): \n");
	prev = '\n';
	while((c = getchar()) != STOP) {
		n_chars++;
		if(c == '\n')
			n_lines++;
		if(!isspace(c) && !inword) {
			inword = true; // ������ �����
			n_words++;
		}
		if(isspace(c) && inword)
			inword = false; // ��������� ����� �����
		prev = c;	// ���������� �������� �������
	}
	if(prev !='\n')
		p_lines = 1;
	printf("symbols = %ld, words = %d, strings = %d, ",
		n_chars, n_words, n_lines);
	printf("incomplete line = %d\n", p_lines);
	
	return 0;
}

