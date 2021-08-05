// модифицирует строку
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 81

void ToUpper(char *);
int PunctCount(const char *);

int mod_str(void) {
	char line[LIMIT];
	char *find;
	
	puts("Enter string:");
	fgets(line, LIMIT, stdin);
	find = strchr(line, '\n');
	if(find)
		*find = '\0';
	ToUpper(line);
	puts(line);
	printf("This is string contains of %d signs punctuation.\n",
		PunctCount(line));
	
	return 0;
}

void ToUpper(char *str) {
	while(*str) {
		*str = towupper(*str);
		str++;
	}
}

int PunctCount(const char *str) {
	int ct = 0;
	while (*str) {
		if(ispunct(*str))
			ct++;
		str++;
	}
	return ct;
}
