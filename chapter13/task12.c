#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define LEVELS 10
const char trans[LEVELS + 1] = " .':~*=&%@";

void create_file(FILE *fp);
void MakePic(int data[][COLS], char pic[][COLS], int rows);
void init(char arr[][COLS], char ch);

int task12(void) {
	int r, c;
	int picIn[ROWS][COLS];
	char picOut[ROWS][COLS];
	FILE *infile;
	
//	create_file(fp);
	init(picOut, 'S');
	
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
	
	MakePic(picIn, picOut, ROWS);
	
	for(r=0; r<ROWS; r++) {
	 	for(c=0; c<COLS; c++) {
	 		putchar( picOut[r][c] );
		 }
		 putchar('\n');
	}
	
	if(fclose(infile) != 0) fputs("Can not create file 'task12.dat'.\n", stderr);
	return 0;
}

void MakePic(int data[][COLS], char pic[][COLS], int rows) {
	int r, c;
	for(r=0; r < ROWS; r++)
		for(c=0; c < COLS; c++)
			pic[r][c] = trans[data[r][c]];
}

void init(char arr[][COLS], char ch) {
	int r, c;
	for(r=0; r < ROWS; r++)
		for(c=0; c < COLS; c++)
			arr[r][c] = ch;
}

void create_file(FILE *fp) {
	int c, r;
	
	if((fp = fopen("task12.dat", "wb")) == NULL) {
		fputs("Can not create file 'task12.dat'.\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	srand(time(0));
	
	for(r=0; r<20; r++) {
		for(c=0; c<30; c++) {
			fprintf(fp, "%d ", rand() % 10);			
		}
		putc('\n', fp);
	}
		
	
	if(fclose(fp) != 0) fputs("Can not create file 'task12.dat'.\n", stderr);
}
