// ��������� ���� � ���������� ��� ����������
#include <stdio.h>
#include <stdlib.h> // ��� exit()

int file_eof(void) {
	int ch;
	FILE *fp;
	char fname[50];
	
	printf("Enter name of file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if(fp == NULL) {
		printf("Can't open file. Program is finished.\n");
		exit(1);
	}
	// ������� getc(fp) �������� ������ �� ��������� �����
	while((ch = getc(fp)) != EOF)
		putchar(ch);
	fclose(fp);
	
	return 0;
}
