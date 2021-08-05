// interface of queue
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

//typedef int Item;
typedef struct item {
	long arrive;
	int processtime;
} Item;

#define MAXQUEUE 10
typedef struct node {
	Item item;
	struct node *next;
} Node;
typedef struct queue {
	Node *front;	// pointer on start of queue
	Node *rear;	// pointer on end of queue
	int items;	// count of elements of queue
} Queue;

// opearion: initialization queue
// before statement: pq points on queue
// after statement: queue initialized empty contain
void InitializationQueue(Queue *pq);

// operation: checking, queue is full, isn't it
// before statement: pq points on early initialized queue
// after statement: return True, if queue is full, and False in else
bool QueueIsFull(const Queue *pq);

// operation: checking, queue is empty, isn't it
// before statement: pq points on early initialized queue
// after statement: return True, if queue is empty, and False in else
bool QueueIsEmpty(const Queue *pq);

// operation: define count elements in queue
// before statement: pq points on early initialized queue
// after statement: return count elemets in queue
int QueueItemCount(const Queue *pq);

// operation: adding element in end of queue
// before statement: pq points on early initialized queue
//		element must be moving in end of queue
// after statement: if empty is not empty, element moving
// 	in end of queue and function returns True;
//	in else queue stay permanently,
//	and function return False
bool EnQueue(Item item, Queue *pq);

// operation: removing element from start of queue
// before statement: pq points on early initialized queue
// after statement: if empty is not empty, element in start of queue
// 	copyes in *pitem and removing from queue,
//	and function retun True;
//	if operation is empied queue, queue
// 	resetup in empty status.
// 	If queue is empty start from begin, it stays permanently,
//	and function return False;
bool DeQueue(Item *pitem, Queue *pq);

// operation:	clearning queue
// before statement: pq points in early initialized queue
// after statement: queue is empty
void EmptyTheQueue(Queue *pq);

#endif
