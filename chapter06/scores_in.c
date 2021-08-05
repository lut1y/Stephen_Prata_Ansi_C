// ������������� ������ ��� ��������� ��������
#include <stdio.h>
#define SIZE 10
#define PAR 72

int scores_in(void) {
	int index, score[SIZE];
	int sum = 0;
	float average;
	
	printf("Enter %d results of golf game: \n", SIZE);
	for(index = 0; index < SIZE; index++)
		scanf("%d", &score[index]); // ������ 10 ����������� ���� �����
	printf("Entered next results:\n");
	for(index = 0; index < SIZE; index++)
		printf("%5d", score[index]); // �������� �������� ����������
	printf("\n");
	for(index = 0; index < SIZE; index++)
		sum += score[index];	// �������� �����������
	average = (float) sum/SIZE; // ����������� �������� �����
	printf("Sum results = %d, average value = %.2f\n", sum, average);
	printf("Received handicap equals %.0f.\n", average - PAR);
	
	return 0;
}
