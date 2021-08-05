// use interface Queue
// compile with queue.c
#include <stdio.h>
#include <stdlib.h> 	// rand() and srand()
#include <time.h>	// time()
#include "queue.h"	// change definition of type Item
#define MIN_PER_HR 60.0

bool newcustomer(double x);		// ������� ����� ������?
Item customertime(long when);	// ��������� ���������� �������

int task4(void) {
	Queue line1, line2;
	Item temp1;			// ���������� ����������� ������ �������
	Item temp2;			// ���������� ����������� ������ �������
	int hours;			// ���������� ����� �������������
	int perhour;		// ������� ���������� ����������� �������� � ���
	long cycle, cyclelimit;	// ������� � ��������� �������� �����
	long turnaways = 0;	// ���������� ����������� ��������, ������� ���� �������� � ������������
	long customers = 0;	//  ���������� ����������� ��������, ������� ���������� � �������
	long served = 0;	// ���������� ������������� ����������� ��������
	long sum_line = 0;	 // ������������� �������� ����� ������� �� ������� ������
	int wait_time1 = 0;	 // ���������� �����, ���������� �� ���� �������, ����� ���������� �������������
	int wait_time2 = 0;	 // ���������� �����, ���������� �� ���� �������, ����� ���������� �������������
	double min_per_cust; // ������� ���������� ����� ����� ���������� ��������
	long line_wait1 = 0;	// ������������� �������� �������, ����������� � ������� ����� ��������� �� ������� ������
	long line_wait2 = 0;	// ������������� �������� �������, ����������� � ������� ����� ��������� �� ������� ������

	InitializationQueue(&line1);
	InitializationQueue(&line2);
	srand((unsigned int) time(0));	// ��������� ������������� rand()
	puts("Learn example: consulting office of Zigmung Lander");
	puts("Enter duration modeling in hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter average count of clienets per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour; // ������� ����� �� ������ ��������

	for (cycle = 0; cycle < cyclelimit; cycle++) {
		if(newcustomer(min_per_cust)) {
			if(QueueIsFull(&line1) && QueueIsFull(&line2)) 
					turnaways++;	
			else {
				customers++;				
				if(QueueItemCount(&line1) < QueueItemCount(&line2))  {
					temp1 = customertime(cycle);
					EnQueue(temp1, &line1);
				} else {
					temp2 = customertime(cycle);
					EnQueue(temp2, &line2);	
				}
			}						
		}	
		if(wait_time1 <= 0 && !QueueIsEmpty(&line1)) {	// ���� ������������ ����������� � ������� �� �����
			DeQueue(&temp1, &line1);
			wait_time1 = temp1.processtime;
			line_wait1 += cycle - temp1.arrive;
			served++;
		}
		if(wait_time2 <= 0 && !QueueIsEmpty(&line2)) {	// ���� ������������ ����������� � ������� �� �����
			DeQueue(&temp2, &line2);
			wait_time2 = temp2.processtime;
			line_wait2 += cycle - temp2.arrive;
			served++;
		}
		
		if(wait_time1 > 0)
			wait_time1--;
		if(wait_time2 > 0)
			wait_time2--;
			
		sum_line += QueueItemCount(&line1) + QueueItemCount(&line2);
	}
	if(customers > 0) {
		printf("\treceived clients: %ld\n", customers);
		printf("\tserved clients: %ld\n", served);
		printf("\tturnaway: %ld\n", turnaways);
		printf("\taverage length queue: %.2f\n", (double) sum_line/served);
		printf("\taverage time waiting: %.2f min\n", (double) (line_wait1+line_wait2)/served);
	} else
		puts("Clients are ansent!");
	EmptyTheQueue(&line1);
	EmptyTheQueue(&line2);
	puts("Program is finished.");

	return 0;
}

/*bool newcustomer(double x) { // ���������� ������ � ������� ���� ���������� ������
	if(rand() * x / RAND_MAX < 1) 
		return true;	
	else
		return false;
}

Item customertime(long when) {	// ������������� ����� arrive � processtime ��������� Item
	Item cust;
	
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}*/
