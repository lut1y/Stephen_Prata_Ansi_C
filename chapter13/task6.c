// ���������� ������ �� 2/3-��!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 81

char *sgets(char*, int);

int task6(void) {
	FILE *in, *out;
	int ch;
	char fnamein[LEN],
		 fnameout[LEN];
	int count = 0;
	
	printf("Enter name of file: ");
	sgets(fnamein, LEN);
	
	// ��������� �����
	if((in=fopen(fnamein, "r")) == NULL) {
		fprintf(stderr, "Can not open file \"%s\"\n",
			fnamein);
		exit(EXIT_FAILURE);
	}
	// ��������� ������
	strncpy(fnameout, fnamein, LEN-5); // ����������� ����� �����
	fnameout[LEN-5] = '\0';
	strcat(fnameout, ".red");		// ���������� .red
	if((out = fopen(fnameout, "w")) == NULL) {
		fprintf(stderr, "Can not create output file.\n");
		exit(3);
	}
	// ����������� ������
	while((ch = getc(in)) != EOF)
		if(count++ % 3 == 0)
			putc(ch, out);		// �������� ������ ������ ������
	// �������
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files.\n");
	
	return 0;
}
