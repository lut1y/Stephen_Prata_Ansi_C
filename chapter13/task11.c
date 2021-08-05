#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 81

int task11(int argc, char **argv) {
	FILE *fp;
	char str[SIZE];
	char *find;
	
	if(argc < 3) {
		fprintf(stderr, "Usage: %s <string> <file>.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if((fp = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Can not open file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while(fgets(str, SIZE, fp) != NULL) {
		find = strstr(str, argv[1]); 
		if(find) 
			printf("%s", str);
		find = NULL;
	}
	
	if(fclose(fp) != 0) 
		fprintf(stderr, "Can not close file.\n");
	printf("Program is finished.\n");
	return 0;
}
