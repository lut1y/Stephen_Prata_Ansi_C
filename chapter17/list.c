#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist) {
//	*plist = NULL;

// taks2
//	plist->head = plist->end = NULL;

// task3
	int i=0;
	for(; i< MAXSIZE; i++) {
		plist->entries[i].rating = 0;
		strcpy(plist->entries[i].title, "");
	}
	plist->items = 0;
}

bool ListIsEmpty(const List *plist) {
	/*if(*plist == NULL)
		return true;
	else
		return false;*/	
	
	// task2
	/*if(plist->head == NULL || plist->end == NULL)
		return true;
	else
		return false;*/
		
	// task3
	if(plist->items == 0) 
		return true;
	else return false;
}

bool ListIsFull(const List *plist) {
	/*Node *pt;
	bool full;
	
	pt = (Node *) malloc(sizeof(Node));
	if(pt == NULL)
		full = true;
	else
		full = false;
	free(pt);
	return full;*/
	
	// task3
	if(plist->items > MAXSIZE) return true;
	else return false;
}

unsigned int ListItemCount(const List *plist) {
	/*unsigned int count = 0;
	Node *pnode = *plist;

	while(pnode != NULL) {
		++count;
		pnode = pnode->next;
	}
	return count;*/
	
	// task2
	/*	
	Node *pnode = plist->head;
	while(pnode != plist->end) {
		++count;
		pnode = pnode->next;
	}
	return count;*/
	
	// task3
	return plist->items;
}

bool AddItem(Item item, List *plist) {
	/*Node *pnew;
	Node *scan = *plist;*/
	
	//task2
//	Node *scan = plist->head;

	
	/*pnew = (Node *) malloc(sizeof(Node));
	if(pnew == NULL)
		return false;
	
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if(scan == NULL)
		*plist = pnew;
	else {
		while(scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}
	return true;*/
	
	// task2
	/*CopyToNode(item, pnew);
	if(scan == NULL) {
		plist->head = plist->end = pnew;
		pnew->next = NULL;
	}
	else {
		while(scan->next != NULL)
			scan = scan->next;
		plist->end = scan->next = pnew;
	}		
	return true;*/
	
	// task3
	if(plist->items > MAXSIZE-1) return false;
	else {		
		plist->entries[plist->items].rating = item.rating;
		strcpy(plist->entries[plist->items].title, item.title);
		plist->items++;
	}
	return true;
}

void Traverse(const List *plist, void (* pfun)(Item item) ) {
//	Node *pnode = *plist;
	
// task2	
//	Node *pnode = plist->head;
	
	/*while(pnode != NULL) {
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}*/
	
// task3
	int i;
	for(i=0; i<plist->items; i++) {
		(*pfun)(plist->entries[i]);
	}
}

void EmptyTheList(List *plist) {
	/*Node *psave;

	while(*plist != NULL) {
		psave = (*plist)->next;	// сохраняем адрес след. узла
		free(*plist);			// освобождение текущего узла
		*plist = psave;			// переход к следующему узлу
	}*/
	
	
	// task2
	/*while(plist->head != NULL) {
		psave = (plist->head)->next;	// сохраняем адрес след. узла
		free(plist->head);			// освобождение текущего узла
		plist->head = psave;			// переход к следующему узлу
	}*/
	
	// task3
	plist->items = 0;
}

static void CopyToNode(Item item, Node *pnode) {
	pnode->item = item;
}
