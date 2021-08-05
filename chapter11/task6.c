#include <stdio.h>
#include <string.h>

int is_within(char sym, const char *p);

int task6(void) {
	char s[] = "Example string";
	
	printf("In string '%s' symbol '%c' in position: %d\n",
		s, 'm', is_within('m', s));
		
	return 0;
}

int is_within(char sym, const char *p) {
//	char *p;
	int i=1;
	
//	p = st;	
	while(*p) {
		if(*p == sym){
			return i;
		}
		i++;	
		p++;
	}
	return 0;	
}
