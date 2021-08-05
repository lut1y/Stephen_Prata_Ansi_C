// ������������� ������ ��������
#include <stdio.h>

void report_count();
void accumulate(int k);
int count = 0;	// ������� ��������� � �������� �����, ������� ����������

int parta(void) {
	int value;		// �������������� ����������
	register int i;	// ����������� ����������
	
	printf("Enter positive integer number (0 for finishing): ");
	while(scanf("%d", &value) == 1 && value > 0) {
		++count; 	// ������������� ���������� � �������� ��������� � ������� ������
		for(i = value; i >= 0; i--)
			accumulate(i);
		printf("Enter positive integer number (0 for finishing): ");
	}
	report_count();
	
	return 0;
}

void report_count() {
	printf("Cycle completed %d once(s)\n", count);
}
