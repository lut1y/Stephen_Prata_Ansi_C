// использование функции puts()
#include <stdio.h>
#define DEF "I am string defined directive #define."

int put_out(void) {
	char str1[80] = "Array was initialized my values.";
	const char *str2 = "Pointer was initialized my values.";
	puts("I am argument of function puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]); // аналог str1+5
	puts(str2 + 4);	
	
	return 0;
}
