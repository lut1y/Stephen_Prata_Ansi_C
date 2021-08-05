// использование fprintf(), fscanf(), rewind()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int addaword(void) {
	FILE *fp;
	char words[MAX];
	
	if((fp=fopen("wordy", "a+")) == NULL) {
		fprintf(stdout, "Can not open file \"wordy\".\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter words for adding in file; for finishing");
	puts("enter symbol '#' in start of string.");
	while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);

	puts("Content of file:");
	rewind(fp);		/* возврат в начало файла */
	while(fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("Ready!");
	if(fclose(fp) != 0)
		fprintf(stderr, "Error in closing file\n");
		
	return 0;
}
