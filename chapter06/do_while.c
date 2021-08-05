// цикл с постусловием
#include <stdio.h>

int do_while(void) {
	const int secret_code = 13;
	int code_entered;
	
	do {
		printf("To enter in club of treatment triscadecaphobia, \n");
		printf("please, enter secret code: ");
		scanf("%d", &code_entered);
	} while(code_entered != secret_code);
	printf("Congratulations! You were cured!\n");
	
	return 0;
}
