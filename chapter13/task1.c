// ������������� ������������ �����-������
#include <stdio.h>
#include <stdlib.h>  // �������� exit()

#define SIZE 64

int task1(void) {
	int ch;		// ����� ��� �������� ������� ������� �� ���� ������
	FILE *fp;	// "��������� �����"
	char name[SIZE];
	unsigned long count = 0;
	
	printf("Enter name of file: ");
	s_gets(name, SIZE);
	
	if((fp=fopen(name, "r")) == NULL) {
		printf("Can't open %s\n", name);
		exit(EXIT_FAILURE);
	}
	
	while((ch = getc(fp)) != EOF) { // ������������ ���������� �����
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("\nFile %s constains %lu symbols\n", name, count);
	
	return 0;
}
