// testing interface Queue with help of Driver
#include <stdio.h>
#include "queue.h"

int use_q(void) {
	Queue line;
	Item temp;
	char ch;

	InitializationQueue(&line);
	puts("Testing interface of Queue. To add value enter 'a'.");
	puts("To delete value enter 'd', or enter 'q' for exit from program.");
	while((ch=getchar()) != 'q') {
		if(ch != 'a' && ch != 'd')
			continue;
		if(ch == 'a') {
			printf("Integer number for adding: ");
			scanf("%d", &temp);
			if(!QueueIsFull(&line)) {
				printf("Moving %d in queue\n", temp);
				EnQueue(temp, &line);
			} else
				puts("Queue is full!");
		}
		else
		{
			if(QueueIsEmpty(&line))
				puts("Elements for removing is absent!");
		 	else {
				DeQueue(&temp, &line);
				printf("Removing %d from queue\n", temp);
			}
		}
		printf("%d element(s) in queue\n", QueueItemCount(&line));
		puts("To add enter 'a', to remove - enter 'd', or 'q' for exit from program:");
	}
	EmptyTheQueue(&line);
	puts("Program is finished.");

	return 0;
}
