// сокращение файлов на 2/3-ти!
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
	
	// настройка ввода
	if((in=fopen(fnamein, "r")) == NULL) {
		fprintf(stderr, "Can not open file \"%s\"\n",
			fnamein);
		exit(EXIT_FAILURE);
	}
	// настройка вывода
	strncpy(fnameout, fnamein, LEN-5); // копирование имени файла
	fnameout[LEN-5] = '\0';
	strcat(fnameout, ".red");		// добавление .red
	if((out = fopen(fnameout, "w")) == NULL) {
		fprintf(stderr, "Can not create output file.\n");
		exit(3);
	}
	// копирование данных
	while((ch = getc(in)) != EOF)
		if(count++ % 3 == 0)
			putc(ch, out);		// выводить каждый третий символ
	// очистка
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files.\n");
	
	return 0;
}
