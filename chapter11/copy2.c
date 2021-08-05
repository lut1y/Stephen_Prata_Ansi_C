// демонстрация использования strcpy()
#include <stdio.h>
#include <string.h>

#define WORDS "WORST"
#define SIZE 40

int copy2(void) {
	const char *orig = WORDS;
	char copy[SIZE] = "Will be better, than you would can be!";
	char *ps;
	
	puts(orig);
	puts(copy);
	ps = strcpy(copy + 8, orig);
	puts(copy);
	puts(ps);
	
//	puts(copy + 14);
	
	return 0;
}
