#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

char *sgets(char*, int);

int task10(void) {
	FILE *fp;
	char fname[SIZE];
	long pos;
	char ch;
	
	printf("Enter name of file: ");
	sgets(fname, SIZE);	
	if((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "Can not open file %s.\n", fname);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter position in file: ");
	while((scanf("%ld", &pos) == 1) && (pos > 0)) {
		fseek(fp, pos, SEEK_SET);
		ch = getc(fp);
		while((ch != '\n') && (ch != EOF) )  {
			putchar(ch);
			ch = getc(fp);
		}
		putchar('\n');
		printf("Enter next position in file: ");		
	}
	if(fclose(fp) != 0) {
		fprintf(stderr, "Can not close file.\n");
	}
	printf("Program is finished.\n");
	
	return 0;
}
