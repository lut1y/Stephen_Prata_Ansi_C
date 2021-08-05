#include <stdio.h>
#include <stdlib.h>

int task2(int argc, char **argv) {
	FILE *src, *dest;
	int ch;
	
	if(argc < 3) {
		printf("Using: %s <file_source> <file_destionation>.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if((src = fopen(argv[1], "rb")) == NULL) {
		printf("Can not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	if((dest = fopen(argv[2], "wb")) == NULL) {
		printf("Can not open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while((ch=getc(src)) != EOF) {
		fputc(ch, dest);
	}
	
	if(fclose(dest) != 0) {
		printf("%s can not close", argv[2]);
		exit(EXIT_FAILURE);	
	}
	if(fclose(src) != 0) {
		printf("%s can not close", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("Copy is complited.\n");
	
}
