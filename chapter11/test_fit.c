// использование функции укорачивания строк
#include <stdio.h>
#include <string.h> // содержит прототипы строковых функций

void fit(char *, unsigned int);

int test_fit(void) {
	char mesg[] = "All must be maximally usual,"
		" but not more.";
	
	puts(mesg);
	fit(mesg, 35);
	puts(mesg);
	puts("Consider more some string.");
	puts(mesg + 36); // выводим остаток, который никуда не делся
	
	return 0;
}

void fit(char *string, unsigned int size) {
	if(strlen(string) > size)
		string[size] = '\0';
}
