#include <stdio.h>
#include <string.h>

int compback(void) {
	printf("strcmp(\"A\", \"A\") return ");
	printf("%d\n", strcmp("A", "A"));

	printf("strcmp(\"A\", \"B\") return ");
	printf("%d\n", strcmp("A", "B"));
	
	printf("strcmp(\"B\", \"A\") return ");
	printf("%d\n", strcmp("B", "A"));
	
	printf("strcmp(\"C\", \"A\") return ");
	printf("%d\n", strcmp("C", "A"));
	
	printf("strcmp(\"Z\", \"a\") return ");
	printf("%d\n", strcmp("Z", "a"));
	
	printf("strcmp(\"apples\", \"apple\") return ");
	printf("%d\n", strcmp("apples", "apple"));
	// apples > apple, поэтому возвращается 1	
	return 0;
}
