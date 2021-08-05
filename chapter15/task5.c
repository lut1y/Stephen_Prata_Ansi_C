#include <stdio.h>
#include <limits.h>

char *itobs(int, char *);
void show_bstr(const char *);
unsigned int rotate_1(unsigned int x, unsigned int b);

int task5(void) {
	char str[sizeof(char)*8 + 1];
	int number;
	
	printf("Enter number (or 'q' for exit): ");
	while(scanf("%d", &number) == 1) {
		
		printf("%d it's ", number);
		show_bstr(itobs(number, str));
		putchar('\n');
		show_bstr(itobs(rotate_1(number, 4), str));
		putchar('\n');
		printf("Enter next number (or 'q' for exit): ");
	}
	
	puts("Program is finished.");
	return 0;
}

unsigned int rotate_1(unsigned int n, unsigned int b) { // (101, 4)
	static const int size = CHAR_BIT * sizeof(int); // 32
	unsigned int overflow;
	
	b %= size;	// возьмем b правильным значением
	
	overflow = n >> (size - b);
	return (n << b) | overflow;
}
