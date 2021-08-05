#include <stdio.h>
#include <stdlib.h>

int task4(int argc, char **argv) {
	FILE *fp;
	int i = 1,
		byte;
	
	if(argc == 0) {
		printf("Using: %s <file> ... <file>", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	for(i = 1; i < argc; i++ ) {
		if((fp = fopen(argv[i], "rb")) == NULL) {
			printf("Can not open %s.\n", argv[i]);
			continue;
		}
		
		printf("*** %s ***\n", argv[i]);
		while((byte = getc(fp)) != EOF)
			putchar(byte);
		
		printf("******\n\n");
		if(fclose(fp) != 0)
			printf("Can not close %s.\n", argv[i]);
	}		
	puts("Program is finished.\n");
	return 0;
}
