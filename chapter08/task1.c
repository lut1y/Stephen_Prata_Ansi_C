#include <stdio.h>

int task1(void) {
	int ch,
		count = 0;
	
	while((ch = getchar()) != EOF)
		count++;
	printf("%d symbols to end of file.\n", count);
	return 0;
} 
