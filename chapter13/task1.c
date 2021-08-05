// использование стандартного ввода-вывода
#include <stdio.h>
#include <stdlib.h>  // прототип exit()

#define SIZE 64

int task1(void) {
	int ch;		// место для хранения каждого символа по мере чтения
	FILE *fp;	// "указатель файла"
	char name[SIZE];
	unsigned long count = 0;
	
	printf("Enter name of file: ");
	s_gets(name, SIZE);
	
	if((fp=fopen(name, "r")) == NULL) {
		printf("Can't open %s\n", name);
		exit(EXIT_FAILURE);
	}
	
	while((ch = getc(fp)) != EOF) { // посимвольное считывание файла
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("\nFile %s constains %lu symbols\n", name, count);
	
	return 0;
}
