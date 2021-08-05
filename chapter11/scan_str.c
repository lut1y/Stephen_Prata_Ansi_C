// использование функции scanf()
#include <stdio.h>

int scan_str(void) {
	char name1[11], name2[11];
	int count;
	
	printf("Enter two names.\n");
	count = scanf("%5s %10s", name1, name2);
	printf("There is read %d names: %s and %s.\n",
		count, name1, name2);
	
	return 0;
}
