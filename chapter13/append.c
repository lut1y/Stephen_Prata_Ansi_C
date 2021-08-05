// ���������� ����������� ������ � ���� ����������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append_(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int append(void) {
	FILE *fa, *fs;	// fa ��� ����� ����������, fs ��� ���������� �����
	int files = 0;	// ���������� ���������� ������
	char file_app[SLEN];	// ��� ����� ����������
	char file_src[SLEN];	// ��� ���������� �����
	int ch;
	
	puts("Enter name of file: ");
	s_gets(file_app, SLEN);
	if((fa=fopen(file_app, "a+")) == NULL) {
		fprintf(stderr, "Can not open %s\n", file_app);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
		fputs("Can not create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("Enter name of first origin file (or empty string for finishing):");
	while(s_gets(file_src, SLEN) && file_src[0] != '\0') {
		if(strcmp(file_src, file_app) == 0)
			fputs("Adding file in end of myself is impossible\n", stderr);
		else if((fs=fopen(file_src, "r")) == NULL)
			fprintf(stderr, "Can not open %s\n", file_src);
		else {
			// ������������� �������������� �����
			if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
				// �.�. buf = NULL, ������� ���� �������� ������ ��� �����
				// BUFSIZE ������ ������
				// ����� �����������: _IOFBF - ������ �����������
				fputs("Can not create input buffer\n", stderr);
				continue;
			}
			append_(fs, fa);
			if(ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n",
					file_src);
			if(ferror(fa) != 0)
				fprintf(stderr, "Error in writing file %s.\n",
					file_app);
			fclose(fs);
			files++;
			printf("Content of file %s added.\n", file_src);
			puts("Enter name next file (or empty string for finishing):");
		}
	}
	printf("Adding is finished. Count of added files: %d.\n", files);
	rewind(fa);
	printf("Content %s:\n", file_app);
	while((ch=getc(fa)) != EOF)
		putchar(ch); 
	puts("\nDisplay is finished.");
	fclose(fa);	
	return 0;
}

void append_(FILE *source, FILE *dest) {
	size_t bytes;
	static char temp[BUFSIZE];	// �������� ������ ���� ���
	while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
	// <���������� ������� ����������� ���������> = fread(
	// <����� ����� ��� ������>, 
	// <������ � ������ ������>, 
	// <���������� ����� �������>, 
	// <�������� ����������>)
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if(ret_val) {
		find = strchr(st, '\n');
		if(find)			// ����� ������� ����� ������
			*find = '\0';	// ���� ����� �� �������� NULL,
		else				// ��������� ���� ������� ������
			while(getchar() != '\n') continue;
	}
	return ret_val;
}
