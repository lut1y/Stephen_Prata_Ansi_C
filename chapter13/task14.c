#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern const char symbols[];

void create_file(FILE *fp);
void MakePic_(int rows, int cols, int data[rows][cols], char pic[rows][cols]);
void init_(int rows, int cols, char arr[rows][cols], char ch);
void interference_suppression(int rows, int cols, int pic[rows][cols]);

int task14(void) {
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
	
	for(r=0; r<rows; r++)
	 	for(c=0; c<cols; c++)
	 		fscanf(infile, "%d", &picIn[r][c]);
	
	
	for(r=0; r<rows; r++) {
	 	for(c=0; c<cols; c++) {
	 		printf("%d ", picIn[r][c] );
		 }
		 putchar('\n');
	}
	putchar('\n');	
	
	interference_suppression(rows, cols, picIn);
	
	for(r=0; r<rows; r++) {
	 	for(c=0; c<cols; c++) {
	 		printf("%d ", picIn[r][c] );
		 }
		 putchar('\n');
	}
		 
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

void interference_suppression(int rows, int cols, int pic[rows][cols]) {
	int r, c;
	
	for(r = 0; r < rows; r++) 
		for(c = 0; c < cols; c++) {
			if(r == 0) {
				if(c == 0) 
					if(abs(pic[r][c] - pic[r+1][c]) > 1 || abs(pic[r][c] - pic[r][c+1]) > 1)
						pic[r][c] = (pic[r+1][c] + pic[r][c+1]) / 2;
				else if(c == cols-1)
					if(abs(pic[r][c] - pic[r+1][c]) > 1 || abs(pic[r][c] - pic[r][c-1]) > 1)
						pic[r][c] = (pic[r+1][c] + pic[r][c-1]) / 2;
				else
					if(abs(pic[r][c] - pic[r+1][c]) > 1 || abs(pic[r][c] - pic[r][c+1]) > 1 ||
							abs(pic[r][c] - pic[r][c-1]) > 1)
						pic[r][c] = (pic[r+1][c] + pic[r][c-1] + pic[r][c+1]) / 3;
			} else if(r == rows-1) {
				if(c == 0)
					if(abs(pic[r][c] - pic[r-1][c]) > 1 || abs(pic[r][c] - pic[r][c+1]) > 1)
						pic[r][c] = (pic[r-1][c] + pic[r][c+1]) / 2;
				else if(c == cols-1)
					if(abs(pic[r][c] - pic[r-1][c]) > 1 || abs(pic[r][c] - pic[r][c-1]) > 1)
						pic[r][c] = (pic[r-1][c] + pic[r][c-1]) / 2;
				else
					if(abs(pic[r][c] - pic[r][c-1]) > 1 || abs(pic[r][c] - pic[r-1][c]) > 1 ||
							abs(pic[r][c] - pic[r][c+1]) > 1)
						pic[r][c] = (pic[r][c-1] + pic[r-1][c] + pic[r][c+1]) / 3;
			} else {
				if(abs(pic[r][c] - pic[r-1][c]) > 1 || abs(pic[r][c] - pic[r][c+1]) > 1 ||
							abs(pic[r][c] - pic[r+1][c]) > 1 || abs(pic[r][c] - pic[r][c-1]) > 1)
						pic[r][c] = (pic[r][c-1] + pic[r-1][c] + pic[r][c+1] + pic[r+1][c]) / 4;
			}
		}	
}
