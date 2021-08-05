#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char *s_gets(char *st, int n);
int bintodec(const char *pbin);
bool check_val(const char *str);

int task1(void) {
	const size_t SLEN = CHAR_BIT * sizeof(int) + 1;
	char value[SLEN];
	
	printf("Enter binary number with up to %u digits: ", SLEN - 1);
	
	while(s_gets(value, SLEN) && value[0] !='\0') {
		if(!check_val(value)) {
			puts("A binary number contains just 0s and 1s.");
		} else 
			printf("%s = %d\n", value, bintodec(value));
	}
	
	return 0;
}

bool check_val(const char *str) {
	
	while(*str != '\0') {	
		if(*str != '0' && *str != '1') 
			return false;
		++str;
	}
	return true;
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val) {
		find = strchr(ret_val, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n') continue;
	}
	return ret_val;
}

int bintodec(const char *pbin) {
	int i, size = strlen(pbin);
	double result;
	
	for(i = 0, result = 0.0; i < size; i++) 
		if(pbin[i] == '1')
			result += pow(2.0, size-i-1);
		
	return (int) result;
}
