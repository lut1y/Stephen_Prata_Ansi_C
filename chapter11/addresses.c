// адреса строк
#include <stdio.h>
#define MSG "I am special." // адрес 0000000000405000

int addresses(void) {
	char ar[] = MSG; // копия MSG
	const char *pt = MSG;
	
	printf("address \"I am special.\": %p \n", "I am special."); // 0000000000405000
	printf("             address ar: %p \n", ar);				 // 000000000065FDD0
	printf("             address pt: %p \n", pt);				 // 0000000000405000
	printf("            address MSG: %p \n", MSG);				 // 0000000000405000
	printf("address \"I am special.\": %p \n", "I am special."); // 0000000000405000
	
	return 0;
}
