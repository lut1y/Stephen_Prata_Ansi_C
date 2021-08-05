#include <stdio.h>
const int S_PER_M = 60;			// ���������� ������ � ������
const int S_PER_H = 3600;		// ���������� ������ � ����
const double M_PER_K = 0.62137; // ���������� ���� � ���������

int running(void) {
	double distk, distm; // ��������� ������� � ���������� � �����
	double rate; 		 // ������� �������� � ����� � ���
	int min, sec;		 // ����� ������� � ������� � ��������
	int time;			 // ����� ������� ������ � ��������
	double mtime;		 // ����� ������� ����� ���� � ��������
	int mmin, msec;		 // ����� ������� ����� ���� � ������� � ��������
	
	printf("This is program transform running time of distance in metric system\n");
	printf("  during running one mile and calculate your average ");
	printf("speed in miles in hour.\n");
	printf("Enter distance running in kilometers:\n");
	scanf("%lf", &distk); // %lf ��� ���� double
	printf("Enter time in minutes and seconds.\n");
	printf("Start entering from minutes:\n");	
	scanf("%d", &min);
	printf("Now enter seconds:\n");
	scanf("%d", &sec);
	// ��������� ����� � �������
	time = S_PER_M * min + sec;
	// ��������� ��������� � ����
	distm = M_PER_K * distk;
	// ��������� ���� � ������� �� ���������� ������ � ���� ���� ���������� ���� � ���
	rate = distm / time * S_PER_H;
	// ������� ������� �� ���������� ���� ����� ������� ����� ����
	mtime = (double) time / distm;
	mmin = (int) mtime / S_PER_M; // ���������� ������� ���������� �����
	msec = (int) mtime % S_PER_M; // ���������� ������� ���������� ������
	printf("You are running %1.2f km (%1.2f miles) in %d min, %d sec.\n",
		distk, distm, min, sec);
	printf("This speed corresponds running one miles in %d min, ", mmin);
	printf("%d sec.\nYour average speed equals %1.2f miles in hours.\n", msec, rate);
	
	return 0;
}	
