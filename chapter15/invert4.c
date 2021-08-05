// исользование операций с битами для отображения двоичного
// представления чисел
#include <stdio.h>
#include <limits.h>
char *itobs(int, char *);
void show_bstr(const char*);
int invert_end(int num, int bits);

int invert4(void) {
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;
	
	puts("Enter integer numbers and look over their binary representation");
	puts("Unnumber input finish programm.");
	while(scanf("%d", &number) == 1) {
		itobs(number, bin_str);
		printf("%d presents as ", number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Invertion of last 4 bites give\n");
		show_bstr(itobs(number, bin_str));
		putchar('\n');
	}
	puts("Program is finished.");
	
	return 0;
}

int invert_end(int num, int bits) {
	int mask = 0;
	int bitval = 1;
	
	while(bits-- > 0) {
		mask |= bitval;
		bitval <<= 1;
	}
	
	return num ^ mask; // переключение битов
}
