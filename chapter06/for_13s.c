#include <stdio.h>

int for_13s(void) {
	int n; // ���� � ���������� 13, ������� � 2
	for(n = 2; n < 60; n+=13)
		printf("%d \n", n);
	return 0;
}
