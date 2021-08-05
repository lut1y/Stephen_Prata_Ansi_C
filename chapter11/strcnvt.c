// использование функции strtol()
#include <stdio.h>
#include <stdlib.h>

#define LIM 30
char *s_gets(char *st, int n);

int strcnvt(void) {
	char number[LIM];
	char *end;
	long value;
	
	puts("Enter number (or empty string for exit from program):");
	while(s_gets(number, LIM) && number[0] != '\0') {
		value = strtol(number, &end, 10); // по основанию 10
		printf("decimal input, decimal output: %ld, broken on '%s (%d)'\n",
			value, end, *end);
		value = strtol(number, &end, 16); // по основанию 16
		printf("hex input, hex output: %ld, broken on '%s (%d)'\n",
			value, end, *end);
		puts("Next number:");
	}
	puts("Program is finished.\n");
	
	return 0;
}
