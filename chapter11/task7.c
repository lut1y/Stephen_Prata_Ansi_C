#include <stdio.h>
#include <string.h>

char *mystrncpy(char*, char*, int);

int task7(void) {
	char st1[] = "string ";
	char st2[] = "new";
	
	puts(mystrncpy(st1, st2, 5));
	
	return 0;
}

char *mystrncpy(char *st1, char *st2, int n) {
	int i, len_st1;
	char *st = st1;
	
	// подгон€ем вставл€емую строку
	if(strlen(st2) > n) {
		// усекаем
		i = strlen(st2);
		while(i >= n) {
			*(st2 + i) = '\0';
			i--;
		}
	}
	else if(strlen(st2) < n) {
			i = strlen(st2);
			while(i++ < n) 
				*(st2 + i) = '\0';
		 }
	// вставка
	i = 0;
	len_st1 = strlen(st1);
	while(i < n) {
		*(st1 + len_st1 + i) = *(st2 + i);
		*(st1 + len_st1 + i + 1) = '\0';
		i++;
	}
	return st;
}

