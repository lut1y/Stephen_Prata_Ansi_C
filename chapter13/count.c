// ������������� ������������ �����-������

#include <stdio.h>
#include <stdlib.h>  // �������� exit()

int count(int argc, char **argv) {
	int ch;		// ����� ��� �������� ������� ������� �� ���� ������
	FILE *fp;	// "��������� �����"
	unsigned long count = 0;
	
	if(argc != 2) {
		printf("Using: %s <name_of_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}  
	
	if((fp=fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
		
	while((ch = getc(fp)) != EOF) { // ������������ ���������� �����
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("\nFile %s constains %lu symbols\n", argv[1], count);
	
	return 0;
}
