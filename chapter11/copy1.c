// демонстрация strcpy()
#include <stdio.h>
#include <string.h>

#define SIZE 40
#define LIM 5

char *s_gets(char *st, int n);

int copy1(void) {
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i=0;
	
	printf("Enter %d words, that start with q:\n", LIM);
	while(i < LIM && s_gets(temp, SIZE)) {
		if(temp[0] != 'q')
			printf("%s don't start with letter 'q'!\n", temp);
		else {
			strcpy(qwords[i], temp);
			i++;
		}
	}
	puts("List taken words:");
	for(i=0; i<LIM; i++) 
		puts(qwords[i]);
	
	return 0;
}
