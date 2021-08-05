// использование функции strncmp()
#include <stdio.h>
#include <string.h>

#define LISTSIZE 6

int starsrch(void) {
	const char *list[LISTSIZE] = {
		"astronomy",
		"astatiem",
		"astrophisics",
		"ostracism",
		"asterism",
		"astrolabe"
	};
	int count = 0;
	int i;
	
	for(i=0; i < LISTSIZE; i++)
		if(strncmp(list[i], "astro", 5) == 0) {
			printf("Founded: %s\n", list[i]);
			count++;
		}
	printf("Count words in list,"
		" starting with 'astro': %d\n", count);
	
	return 0;
}
