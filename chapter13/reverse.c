// ����������� ����������� ����� � �������� �������
#include <stdio.h>
#include <stdlib.h>

#define CTRL_Z '\032'  /* ������ ����� ����� � ��������� ������ DOS */
#define SLEN 81

int reverse(void) {
	char file[SLEN];
	char ch;
	FILE *fp;
	long count, last;
	
	puts("Enter name of file for processing: ");
	scanf("%80s", file);
	if((fp=fopen(file, "rb")) == NULL) {
		/* ����� ������ ��� ������ */
		printf("reverse can not open %s\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);	// ������� � ����� �����
	last = ftell(fp);
	for(count = 1L; count <= last; count++) {
		fseek(fp, -count, SEEK_END);	// ��������� � �������� �����������
		ch = getc(fp);
		if(ch != CTRL_Z && ch != '\r')
			putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	
	return 0;
}

