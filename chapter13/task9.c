#include <stdio.h>
#include <stdlib.h>
#define MAX 41

int task9(void) {
	FILE *fp;
	char words[MAX];
	int numstr = 1;
	char ch;
	
	if((fp = fopen("wordy", "a+")) == NULL) {
		fprintf(stdout, "Can not open file \"wordy\".\n");
		exit(EXIT_FAILURE);
	}
	// определить номер строки
	while((ch = getc(fp)) != EOF) 
		if(ch == '\n') 
			fscanf(fp, "%d", &numstr);
	
	numstr++;
	puts("Enter words for adding in file; for finishing");
	puts("enter symbol '#' in start of string.");
	while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%d %s\n", numstr, words);
	
	puts("Content of file:");
	rewind(fp);
	while(fscanf(fp, "%d%s", &numstr, words) == 2)
		printf("%d: %s\n", numstr, words);
	puts("Ready!");
	if(fclose(fp) != 0)
		fprintf(stderr, "Error in closing file.\n");
	return 0;
}
