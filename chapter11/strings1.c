#include <stdio.h>
#define MSG "I am symbol string constant."
#define MAXLENGTH 81

int strings1(void) {
	char words[MAXLENGTH] = "I am string, that store in array.";
	const char *pt1 = "Something indicate to me.";
	puts("Here are some strings:");
	// puts() - автомат-ки добавляет символ \n
	puts(MSG); // вывод с директивы
	puts(words); // вывод с массива
	puts(pt1); // вывод с указателя
	words[14] = 'f';
	puts(words);
	
	return 0;
}
