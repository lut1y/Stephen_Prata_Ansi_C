// программа с крупной проблемой ввода-вывода
#include <stdio.h>

void display(char cr, int lines, int width); // тело описано в showchar1

int showchar2(void) {
	int ch;	// выводимый символ
	int rows, cols;
	
	printf("Enter symbol and 2 decimal number: \n");
	while((ch = getchar()) != '\n') {
		if (scanf("%d %d", &rows, &cols) != 2) break;
		display(ch, rows, cols);
		while(getchar() != '\n') continue;
		printf("Enter symbol and 2 decimal number: \n");
		printf("for finishing enter symbol of new string.\n");
	}
	printf("Program is finished!\n");	
	
	return 0;
}
