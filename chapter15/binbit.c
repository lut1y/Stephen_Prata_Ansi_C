// ������������� �������� � ������ ��� ����������� ���������
// ������������� �����
#include <stdio.h>
#include <limits.h> // ��� CHAR_BIT ���������� ����� �� ������

char *itobs(int, char *);
void show_bstr(const char *);

int binbit(void) {
	char bin_str[CHAR_BIT * sizeof(int) + 1]; // 8 * 4 + 1
	int number;
	
	puts("Enter integer numbers and look over their binary representation");
	puts("Unnumber input finish programm.");
	while(scanf("%d", &number) == 1) {
		itobs(number, bin_str);
		printf("%d presents as ", number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Program is finished.");
	
	return 0;
}

char *itobs(int n, char *ps) {
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	
	for(i = size-1; i >= 0; i--, n >>= 1) // 32->0
		// 01 - 1 � ������������ ������� ���������, ���� 1
		ps[i] = (01 & n) + '0'; 	// �������������� ��������� ASCII ��� �������
	ps[size] = '\0';
	
	return ps;
}

// ����������� �������� ������ ������� �� 4
void show_bstr(const char *str) {
	int i = 0;
	
	while(str[i]) {	// ���� �� ����� ������� ������� ������
		putchar(str[i]);
		if(++i % 4 == 0 && str[i]) putchar(' ');
	}
}
