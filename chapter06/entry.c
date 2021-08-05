// цикл с предусловием
#include <stdio.h>

int entry(void) {
	const int secret_code = 13;
	int code_entered;
	
	printf("To enter in club of treatment triscadecaphobia, \n");
		printf("please, enter secret code: ");
	scanf("%d", &code_entered);
	while (code_entered != secret_code) {
		printf("To enter in club of treatment triscadecaphobia, \n");
		printf("please, enter secret code: ");
		scanf("%d", &code_entered);
	}
	printf("Congratulations! You were cured!\n");
	
	return 0;
}
