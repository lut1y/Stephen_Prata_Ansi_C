#ifndef _TREEW_H_
#define _TREEW_H_
#include <stdbool.h>

typedef struct item {
	char word[20];
	int count;
} Item;

#define MAXITEMS 100

typedef struct trnode {
	Item item;
	struct trnode *left;
	struct trnode *right;
} Trnode;

typedef struct tree {
	Trnode *root;
	int size;
} Tree;

void InitializeTreew(Tree *ptree);
bool TreewIsEmpty(const Tree *ptree);
bool TreewIsFull(const Tree *ptree);
int  TreewItemCount(const Tree *ptree);
bool AddItemW(const Item *pi, Tree *ptree);
bool InTreew(const Item *pi, const Tree *ptree);
bool DeleteItemW(const Item *pi, Tree *ptree);
void TraverseW(const Tree *ptree, void (*pfun) (Item item));
void DeleteAllW(Tree *ptree);
const Item *WhereInTree(const Item *pi, const Tree *ptree);

#endif
