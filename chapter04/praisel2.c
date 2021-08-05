// Если ваша реализация не распознает спецификатор %zd
// попробуйте воспользоваться %u или %lu
#include <stdio.h>
#include <string.h>
#define PRAISE "You is outstanding personality."
/*
int main(void) {
	char name[40];
	
	printf("What is your name? ");
	scanf("%s", name);
	printf("Hello, %s. %s\n", name, PRAISE);
	printf("Your name consists of %zd symbols and takes %zd cells of memory.\n",
		strlen(name), sizeof name);
	printf("Praise phrase contains of %zd symbols ", strlen(PRAISE));
	printf("and takes %zd cells of memory.\n", sizeof PRAISE);
	
	return 0;
}*/

