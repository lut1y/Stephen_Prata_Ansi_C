// ��������� ����� ����� ��� ���������� �������� �����
#include <stdio.h>
#define ADJUST 7.31 // ���� �� ����� ������������� ���������

int shoes2(void) {
	
	const double SCALE = 0.333; // ��� ���� ��� ������������� ���������
	double shoe, foot;
	
	printf("Size of shoe (man)   length leg\n");
	shoe = 3.0;
	while (shoe < 18.5) {
		foot = SCALE * shoe + ADJUST;
		printf("%10.1f %15.2f inch\n", shoe, foot);
		shoe = shoe + 1.0;
	}
	printf("If shoes are good, then bring this.\n");	
	
	return 0;
}
