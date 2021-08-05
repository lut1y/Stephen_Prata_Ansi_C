#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128

char *sgets(char *, int);

int task8(int argc, char **argv) {
	char symbol;
	char str[SIZE];
	int i, ct_sym, ch;
	FILE *fp;
	char fname[SIZE];
	
	if(argc < 2) {
		fprintf(stderr, "Usage: %s <symbol> <files...>", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	symbol = argv[1][0];
	
	if(argc == 2) {
		// стандартный ввод
		puts("Enter text: ");
		sgets(str, SIZE);
		ct_sym = 0;
		for(i=0; i < strlen(str); i++)
			if(str[i] == symbol) ct_sym++;
		printf("In stdin symbol '%c' was meeted %d once(s).\n", symbol, ct_sym);
	} else {
		for(i=2; i < argc; i++) {
			if((fp = fopen(argv[i], "r")) == NULL) {
				fprintf(stderr, "Can not open file %s.\n", argv[i]);
				continue;
			}
			ct_sym = 0;
			while((ch = getc(fp)) != EOF) {
				if(ch == symbol) ct_sym++; 
			}
					
			printf("In file %s symbol '%c' was meeted %d once(s).\n", argv[i], symbol, ct_sym);
			if(fclose(fp) != 0) fprintf(stderr, "Can not open file %s.\n", argv[i]);
		}
	}
	printf("Program is finished.\n");
	return 0;
}
