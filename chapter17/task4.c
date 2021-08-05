// use interface Queue
// compile with queue.c
#include <stdio.h>
#include <stdlib.h> 	// rand() and srand()
#include <time.h>	// time()
#include "queue.h"	// change definition of type Item
#define MIN_PER_HR 60.0

bool newcustomer(double x);		// имеется новый клиент?
Item customertime(long when);	// установка параметров клиента

int task4(void) {
	Queue line1, line2;
	Item temp1;			// переменная описывающая нового клиента
	Item temp2;			// переменная описывающая нового клиента
	int hours;			// количество часов моделирования
	int perhour;		// среднее количество пребывающих клиентов в час
	long cycle, cyclelimit;	// счетчик и граничное значение цикла
	long turnaways = 0;	// количество прибывающих клиентов, которым было отказано в обслуживании
	long customers = 0;	//  количество прибывающих клиентов, которые становятся в очередь
	long served = 0;	// количество действительно обслуженных клиентов
	long sum_line = 0;	 // накапливаемое значение длины очереди на текущий момент
	int wait_time1 = 0;	 // количество минут, оставшееся до того момента, когда закончится консультатция
	int wait_time2 = 0;	 // количество минут, оставшееся до того момента, когда закончится консультатция
	double min_per_cust; // среднее количество минут между прибытиями клиентов
	long line_wait1 = 0;	// накапливаемое значение времени, потраченное в очереди всеми клиентами на текущий момент
	long line_wait2 = 0;	// накапливаемое значение времени, потраченное в очереди всеми клиентами на текущий момент

	InitializationQueue(&line1);
	InitializationQueue(&line2);
	srand((unsigned int) time(0));	// случайная инициализация rand()
	puts("Learn example: consulting office of Zigmung Lander");
	puts("Enter duration modeling in hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter average count of clienets per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour; // среднее время на одного человека

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
		if(wait_time1 <= 0 && !QueueIsEmpty(&line1)) {	// если консультация закончилась и очередь не пуста
			DeQueue(&temp1, &line1);
			wait_time1 = temp1.processtime;
			line_wait1 += cycle - temp1.arrive;
			served++;
		}
		if(wait_time2 <= 0 && !QueueIsEmpty(&line2)) {	// если консультация закончилась и очередь не пуста
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

/*bool newcustomer(double x) { // появляется клиент в течение этой конкретной минуты
	if(rand() * x / RAND_MAX < 1) 
		return true;	
	else
		return false;
}

Item customertime(long when) {	// устанавливает члены arrive и processtime структуры Item
	Item cust;
	
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}*/
