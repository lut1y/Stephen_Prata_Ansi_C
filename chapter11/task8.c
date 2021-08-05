#include <stdio.h>
#include <string.h>

char *string_in(char *st1, char *st2);

int task8(void) {
	char *st1 = "data";
	char *st2 = "at";
	char *res = string_in(st1, st2);;
	
	printf("Position from '%s'\n", res);
	
	return 0;
}

char *string_in(char *st1, char *st2) {
	int len1,
		len2 = strlen(st2);
	
	while(strlen(st1) - len2 >=0 ) {
		if(strncmp(st1, st2, len2) == 0) {
			return st1;			
		}
		st1++;
	}
	return NULL;	
}
