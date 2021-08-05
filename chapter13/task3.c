#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 64
char *sgets(char *, int);

int task3(void) {
	FILE *src, *dest;
	char name_src[SIZE],
		 name_dest[SIZE];
	int byte;
	
	printf("Enter name of file-source: ");
	sgets(name_src, SIZE);
	
	if((src = fopen(name_src, "r")) == NULL) {
		printf("Can not open %s.\n", name_src);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter name of file-destination: ");
	sgets(name_dest, SIZE);
	
	if((dest = fopen(name_dest, "w")) == NULL) {
		printf("Can not open %s.\n", name_dest);
		exit(EXIT_FAILURE);
	}
	
	while((byte = getc(src)) != EOF) {
		putc(toupper(byte), dest);
	}
	
	if(fclose(dest) != 0) {
		printf("Can not close %s", name_dest);
		exit(EXIT_FAILURE);
	}
	
	if(fclose(src) != 0) {
		printf("Can not close %s", name_src);
		exit(EXIT_FAILURE);
	}
	
	puts("Coping is complited.");
	return 0;
}

char *sgets(char *st, int n) {
	char *ret_val;
	char *find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val) {
		find = strchr(st, '\n');
		if(find) 
			*find = '\0';
		else
			while(getchar() != '\n') continue;	
	}	
	return ret_val;
}
