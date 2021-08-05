#include <stdio.h>
#include <string.h>

char *s_gets1(char *st, int n) {
	char *ret_val; // return value
	
	ret_val = fgets(st, n, stdin);
	if(ret_val) {
		while(*st !='\n' && *st != '\0')
			st++; 
		if(*st == '\n')
			*st = '\0';
		else
			while(getchar() != '\n') continue;
			
		
	}
	return ret_val;
}

char *s_gets2(char *st, int n) {
	char *ret_val;
	char *find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val) {
		find = strchr(st, '\n');
		if(*find) 
			*find = '\0'; 		
		else
			while(getchar() != '\n') continue;
	}
	return ret_val;
}

int strlen1(const char *st) {
	int ct=0;
	
	while(*st++) ++ct;
	return ct;		
}

int extra_tasks(void) {
	char *str;
	 
	s_gets1(str, 5);
	printf("%s: %d\n", str, strlen1(str));
	
	return 0;
}
