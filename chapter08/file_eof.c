// открывает файл и отображает его содержимое
#include <stdio.h>
#include <stdlib.h> // для exit()

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
	// функция getc(fp) получает символ из открытого файла
	while((ch = getc(fp)) != EOF)
		putchar(ch);
	fclose(fp);
	
	return 0;
}
