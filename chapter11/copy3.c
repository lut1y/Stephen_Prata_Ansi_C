// демострация использования strncpy()
#include <stdio.h>
#include <string.h>

#define SIZE 40
#define TARGSIZE 7
#define LIM 5

char *s_gets(char *st, int n);
int copy3(void) {
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int i=0;
	printf("Enter %d words, that starting with letter 'q':\n", LIM);
	while(i < LIM && s_gets(temp, SIZE)) {
		if(temp[0] != 'q')
			printf("%s don't start with letter 'q'!\n", temp);
		else {
			strncpy(qwords[i], temp, TARGSIZE - 1);
			qwords[i][TARGSIZE - 1] = '\0';
			i++;
		}
	}
	puts("List taken words:");
	for(i=0; i < LIM; i++)
		puts(qwords[i]);
	
	return 0;
}
