// ��������� ����� �����, �������� � ������������� ������
#include <stdio.h>
int summing(void) {
	long num;
	long sum = 0L; // ������������� ���������� sum �����
	int status;
	
	printf("Enter decimal number for subsequent summing: ");
	printf("(or 'q' for finish program): ");
	status = scanf("%ld", &num);
	while(status == 1) {
		sum += num;
		printf("Enter next decimal number (or 'q' for finish program): ");
		status = scanf("%ld", &num);
	}
	printf("Summ entered numbers equals %ld.\n", sum);
	
	return 0;
}
