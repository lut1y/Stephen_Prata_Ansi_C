// binary tree of search 
//		doubled elements not allowed
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

typedef struct item {
	char petname[20];
	char petkind[20];
} Item;

#define MAXITEMS 10
#define SLEN 32

typedef struct trnode {
	Item item;
	struct trnode *left;
	struct trnode *right;
} Trnode;

typedef struct tree {
	Trnode *root;
	int size;
} Tree;

void InitializeTree(Tree *ptree);
bool TreeIsEmpty(const Tree *ptree);
bool TreeIsFull(const Tree *ptree);
int  TreeItemCount(const Tree *ptree);
bool AddItemT(const Item *pi, Tree *ptree);
bool InTree(const Item *pi, const Tree *ptree);
bool DeleteItem(const Item *pi, Tree *ptree);
void TraverseT(const Tree *ptree, void (*pfun) (Item item));
void DeleteAll(Tree *ptree);
#endif
