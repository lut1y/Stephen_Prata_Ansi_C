// ��������� ����� � ��������� �������
#include <math.h>
#include <stdio.h>

int cmpflt(void) {
	const double ANSWER = 3.14159;
	double response;
	
	printf("What is value number PI?\n");
	scanf("%lf", &response);
	// fabs - ���������� �������� � ��������� �������
	while(fabs(response - ANSWER) > 0.0001) {
		printf("Enter value again.\n");
		scanf("%lf", &response);
	}
	printf("Enough near!\n");
	
	return 0;
}
