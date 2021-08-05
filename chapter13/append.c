// добавление содержимого файлов в файл назначения
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append_(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int append(void) {
	FILE *fa, *fs;	// fa для файла назначения, fs для исходящего файла
	int files = 0;	// количество добвляемых файлов
	char file_app[SLEN];	// имя файла назначения
	char file_src[SLEN];	// имя исходящего файла
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
			// устанавливаем альтернативный буфер
			if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
				// т.к. buf = NULL, функция сама выделяет память под буфер
				// BUFSIZE размер буфера
				// режим буферизации: _IOFBF - полная буферизация
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
	static char temp[BUFSIZE];	// выделить память один раз
	while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
	// <количество успешно прочитанных элементов> = fread(
	// <адрес буфер для чтения>, 
	// <размер в байтах буфера>, 
	// <количество таких буферов>, 
	// <файловый дескриптор>)
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if(ret_val) {
		find = strchr(st, '\n');
		if(find)			// поиск символа новой строки
			*find = '\0';	// если адрес не является NULL,
		else				// поместить туда нулевой символ
			while(getchar() != '\n') continue;
	}
	return ret_val;
}
