#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *s_gets(char *st, int n);
bool check_val(const char *str);
char *addzero(char *st, int n);
void show_bstr(const char *str);

int task2(int argc, char** argv) {
	const size_t SLEN = CHAR_BIT * sizeof(int) + 1;	
//	char val1[SLEN], val2[SLEN];	
	char *val1, *val2;	
	char *v1, *v2;	
	
	if(argc == 1) {
		bool status = false;
		
		do {
			printf("Enter first binary number with up to %u digits: ", SLEN - 1);
			s_gets(val1, SLEN);
			if(!check_val(val1)) 
				puts("A binary number contains just 0s and 1s!");	
			else 
				status = true;			
		} while(!status);
		status = false;
		
		do {
			printf("Enter second binary number with up to %u digits: ", SLEN - 1);	
			if(!check_val(val2)) 
				puts("A binary number contains just 0s and 1s!");
			else 
				status = true;			
		} while(!status);
		
	} else {
		val1 = argv[1];
		val2 = argv[2];
		if(!check_val(val1) || !check_val(val2)) {
			printf("A binary numbers contain just 0s and 1s.\n");
			exit(EXIT_FAILURE);
		}	
	}
	printf("%s\n", val1);
	
	if(strlen(val1) < SLEN-1) 
		v1 = addzero(val1, SLEN);
	printf("%p\n", v1);
	printf("str: %s\n", v1);

	if(strlen(val2) < SLEN-1) 
		val2 = addzero(val2, SLEN);
//	printf("address(val2) = %p\n", val2);
	
	return 0;
}

char *addzero(char *st, int n) {
	// st - адрес первого байта
	int i, ct = n-strlen(st)-1;
	char str[n];
	
	for(i=0; i<ct; i++)
		str[i] = '0';
	str[i] = '\0';
	strcat(str, st);	
	st = str;
//	show_bstr(str);
	printf("%p\n", st);
	return st;
}
