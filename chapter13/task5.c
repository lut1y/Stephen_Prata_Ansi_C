#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 4096
#define SIZE 64

void append1(FILE *source, FILE *dest);

int task5(int argc, char **argv) {
	FILE *fp, *dest;
	char filename[SIZE];
	int files = 0,
		ch, i;
	
	if(argc < 3) {
		fprintf(stderr,
			"Usage: %s <append_file>.\n", argv[0]);
			exit(EXIT_FAILURE);
	}
	
	if((dest = fopen(argv[1], "a+")) == NULL) {
			fprintf(stderr, 
				"Can not open file %s.\n", argv[1]);
	}
	if(setvbuf(dest, NULL, _IOFBF, BUFSIZE) != 0) {
		fputs("Can not open output buffer.\n", stderr);
		exit(EXIT_FAILURE);
	}
		
	for(i = 2; i < argc; i++) {
		if(strcmp(argv[i], argv[1]) == 0) {
			fputs("Adding file in end of myself is impossible\n", stderr);
		} if((fp = fopen(argv[i], "r")) == NULL) {		
			fprintf(stderr, "Can not open %s\n", argv[i]);
		}
		else {
			if(setvbuf(fp, NULL, _IOFBF, BUFSIZE) != 0) {
				fputs("Can not create input buffer\n", stderr);
				continue;
			}
			
			append1(fp, dest);
			
			if(ferror(fp) != 0)
				fprintf(stderr, "Error in reading file %s.\n",
					argv[i]);
			if(ferror(dest) != 0)
				fprintf(stderr, "Error in writing file %s.\n",
					argv[1]);
			if(fclose(fp) != 0) {
				fprintf(stderr, "Can not close file %s.\n", argv[i]);
			}
			files++;
			printf("Content of file %s added.\n", argv[i]);
		}
	}
	printf("Adding is finished. Count of added files: %d.\n", files);
	rewind(dest); // перемещаем указатель на начало потока
	printf("Content %s:\n", argv[1]);
	
	while ((ch = getc(dest)) != EOF)
		putchar(ch);
	
	printf("Display is finished.\n");
	
	if(fclose(dest) != 0) {
		fprintf(stderr, "Can not close file %s.\n", argv[1]);
	}
	return 0;
}

void append1(FILE *source, FILE *dest) {
	size_t bytes;
	static char temp[BUFSIZE];
	while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);	
}
