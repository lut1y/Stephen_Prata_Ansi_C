#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEVELS 10
const char symbols[LEVELS + 1] = " .':~*=&%@";

void create_file(FILE *fp);
void MakePic_(int rows, int cols, int data[rows][cols], char pic[rows][cols]);
void init_(int rows, int cols, char arr[rows][cols], char ch);

int task13(void) {
	int rows = 20, cols = 30,
		r, c;
	int picIn[rows][cols];
	char picOut[rows][cols];
	FILE *infile;
	
//	create_file(infile);
	init_(rows, cols, picOut, 'S');
	
	if((infile = fopen("task12.dat", "rb")) == NULL) {
		fputs("Can not create file 'task12.dat'.\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	for(r=0; r<20; r++)
	 	for(c=0; c<30; c++) 
	 		fscanf(infile, "%d", &picIn[r][c]);
		 
	if(ferror(infile)) {
		fprintf(stderr, "Error getting data from file.\n");
		exit(EXIT_FAILURE);
	}
	
	MakePic_(rows, cols, picIn, picOut);
	
	for(r=0; r<rows; r++) {
	 	for(c=0; c<cols; c++) {
	 		putchar( picOut[r][c] );
		 }
		 putchar('\n');
	}
	
	if(fclose(infile) != 0) fputs("Can not create file 'task12.dat'.\n", stderr);
	return 0;
}

void MakePic_(int rows, int cols, int data[rows][cols], char pic[rows][cols]) {
	int r, c;
	for(r=0; r < rows; r++)
		for(c=0; c < cols; c++)
			pic[r][c] = symbols[data[r][c]];
}

void init_(int rows, int cols, char arr[rows][cols], char ch) {
	int r, c;
	for(r=0; r < rows; r++)
		for(c=0; c < cols; c++)
			arr[r][c] = ch;
}
