// use interface Queue
// compile with queue.c
#include <stdio.h>
#include <stdlib.h> 	// rand() and srand()
#include <time.h>	// time()
#include "queue.h"	// change definition of type Item
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int mall(void) {
	Queue line;
	Item temp;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	double min_per_cust;
	long line_wait = 0;

	InitializationQueue(&line);
	srand((unsigned int) time(0));
	puts("Learn example: consulting office of Zigmung Lander");
	puts("Enter duration modeling in hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter average count of clienets per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++) {
		if(newcustomer(min_per_cust)) {
			if(QueueIsFull(&line))
				turnaways++;
			else {
				customers++;
				temp = customertime(cycle);
				EnQueue(temp, &line);
			}
		}	
		if(wait_time <= 0 && !QueueIsEmpty(&line)) {
			DeQueue(&temp, &line);
			wait_time = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if(wait_time > 0)
			wait_time--;
		sum_line += QueueItemCount(&line);
	}
	if(customers > 0) {
		printf("\treceived clients: %ld\n", customers);
		printf("\tserved clients: %ld\n", served);
		printf("\tturnaway: %ld\n", turnaways);
		printf("\taverage length queue: %.2f\n", (double) sum_line/served);
		printf("\taverage time waiting: %.2f min\n", (double) line_wait/served);
	} else
		puts("Clients are ansent!");
	EmptyTheQueue(&line);
	puts("Program is finished.");

	return 0;
}

bool newcustomer(double x) {
	if(rand() * x / RAND_MAX < 1) {
		// printf("rand() * x / RAND_MAX = %.4f\n", (double) rand() * x / RAND_MAX);
		return true;
	}
	else
		return false;
}

Item customertime(long when) {
	Item cust;
	
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
