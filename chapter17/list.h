// head-file for usual linked list
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>	// C99

// declaration, specifical for program

#define TSIZE 45 // size array for saving name

struct film {
	char title[TSIZE];
	int rating;
};

// definistion common types
typedef struct film Item;
typedef struct node {
	Item item;
	struct node *next;
} Node;

//typedef Node *List;

//task2
/*typedef struct list {
	Node *head; // указывает на начало списка
	Node *end;	// указывает на конец списка
} List;*/

// task3
#define MAXSIZE 100
typedef struct list {
	Item entries[MAXSIZE];	// массив  элементов
	int items;				// количество элементов в списке
} List;

// prototype of function

// operation: initialization of list
// before statement: plist points in list
// after statement: list is initialized to empty
void InitializeList(List *plist);

// operation: determine if list is empty
//	plist point on initialized list
// after statement: function return value True, if list
// 	is empty, and False in else
bool ListIsEmpty(const List *plist);

// operation: definition, list is filled, isn't it
// 	plist point in initialized list
// after statement: function return value True, if list
// 	is full, and False in else
bool ListIsFull(const List *plist);

// operation: definition count of elements in list
// 	plist point in initialized list
// after statement: function return number of element in list
unsigned int ListItemCount(const List *plist);

// opearation: adding element in end of list
// before statement: item - element, that will be add in list
//	plist point in initialized list
// after statement: if possible, function add element in
//	end of list and return value True;
//	in else return value False
bool AddItem(Item item, List *plist);

// operation: appling function on every element of list
// 	plist point in initialization list
//	pfun point in function, that get
//	argument Item and have not return value
// after statement: function, that point pfun, perform one
// 	once for even element in list
void Traverse(const List *plist, void (*pfun)(Item item) );

// operation: free allocated memory, if it is plist
// 	point in initialized list
// after statement: any memory, allocated for list,
//	free, and list setup in empty status
void EmptyTheList(List *plist);

#endif
