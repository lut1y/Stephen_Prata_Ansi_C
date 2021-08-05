// программа с крупной проблемой ввода-вывода
#include <stdio.h>

void display(char cr, int lines, int width);

int showchar1(void) {
	int ch;	// выводимый символ
	int rows, cols;
	printf("Enter symbol and 2 decimal number: \n");
	while((ch = getchar()) != '\n') {
		scanf("%d %d", &rows, &cols);
		display(ch, rows, cols);
		printf("Enter symbol and 2 decimal number: \n");
		printf("for finishing enter symbol of new string.\n");
	}
	printf("Program is finished!\n");	
	
	return 0;
}

void display(char cr, int lines, int width) {
	int row, col;
	for(row = 1; row <= lines; row++) {
		for(col = 1; col <= width; col++)
			putchar(cr);
		putchar('\n');
	}
}
