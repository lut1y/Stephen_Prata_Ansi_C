// ������������� ������� ����������
#include <stdio.h>

int units = 0; /* ������� ���������� */
void critic(void);

int global(void) {
	extern int units; /* �������������� ��������� ���������� */
	
	printf("How much lbs is weigh small keg of oil?\n");
	scanf("%d", &units);
	while(units != 56)
		critic();
	printf("You are know it!\n");
	
	return 0;
}

void critic(void) {
	/*�������������� ��������� ���������� �������*/
	printf("You had the bad luck! Try again!\n");
	scanf("%d", &units);
}

