#include <stdio.h>

void printCharXY(char, int, int);

int task3(void) {
	char ch;
	int row, col;
	
	printf("Enter symbol: ");
	while((ch = getchar()) != '#') {
		if(ch == '\n') continue;
		printf("Enter rows and columns: ");
		while(scanf("%d %d", &row, &col) !=2)
			break;
		printCharXY(ch, row, col);
		while(getchar() != '\n') continue;	
		printf("Enter next symbol (or '#' for exit): ");
	}
	
	return 0;
}

void printCharXY(char ch, int row, int col) {
	int i, j;
	
	for(i=0; i<row; i++) {
		for(j=0; j<col; j++)
			putchar(ch);
		putchar('\n');
	}
}
