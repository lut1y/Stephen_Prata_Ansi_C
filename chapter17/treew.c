// function of tree's support 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "treew.h"

// локальный тип данных
typedef struct pair {
	Trnode *parent;
	Trnode *child;
} Pair;

// прототипы локальных функций
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (* pfun) (Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);

// определения функций
void InitializeTreew(Tree *ptree) {
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreewIsEmpty(const Tree *ptree) {
	if(ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreewIsFull(const Tree *ptree) {
	if(ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

int TreewItemCount(const Tree *ptree) {
	return ptree->size;
}

bool AddItemW(const Item *pi, Tree *ptree) {
	Trnode *new_node;
	Pair seek;
	
	if (TreewIsFull(ptree)) {
		fprintf(stderr, "Tree is full\n");
		return false;		// преждевременный возврат
	}
	
	// ищем место для вставки
	if ((seek = SeekItem(pi, ptree)).child != NULL) {	// возвращает место вставки
		// элемент pi найден, то это дубль
		//fprintf(stderr, "Trying of adding of doubled element\n");
		//return false;		
		seek.child->item.count++;
		return true;
	}
	
	new_node = MakeNode(pi);	// указывает на новый узел
	if (new_node == NULL) {
		fprintf(stderr, "Cannot create node\n");
		return false;			// преждевременный возврат
	}
	
	// успешное создание нового узла
	ptree->size++;
	if(ptree->root == NULL)				// случай 1: дерево пустое
		ptree->root = new_node;			// новый узел - корень дерева
	else								// случай 2: дерево не пустое 
		AddNode(new_node, ptree->root);	// добавление узла к дереву
	return true;						// возврат в случае успеха
}

bool InTreew(const Item *pi, const Tree *ptree) {
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

const Item *WhereInTree(const Item *pi, const Tree *ptree) {
	Trnode *pn;
	pn = SeekItem(pi, ptree).child;
	if(pn != NULL)
		return &(pn->item);
	else return NULL;
}

bool DeleteItemW(const Item *pi, Tree *ptree) {
	Pair look;
	look = SeekItem(pi, ptree);
	if(look.child == NULL)
		return false;
	if(look.parent == NULL)		// Удаление корневого элемента
		DeleteNode(&ptree->root);
	else if(look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;
	
	return true;
}

void TraverseW(const Tree *ptree, void (* pfun) (Item item)) {
	if(ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAllW(Tree *ptree) {
	if(ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

// локальные фукции
static void InOrder(const Trnode *root, void (* pfun) (Item item)) {
	if(root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode *root) {
	Trnode *pright;
	if(root != NULL) {
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static void AddNode(Trnode *new_node, Trnode *root) {
	if(ToLeft(&new_node->item, &root->item)) {
		if(root->left == NULL)				// пустое поддерево
			root->left = new_node;			// поэтому добавить сюда узел
		else
			AddNode(new_node, root->left);	// иначе обработать поддерево
	}
	else if (ToRight(&new_node->item, &root->item)) {
		if(root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	} else {								// дубликаты не допускаются
		fprintf(stderr, "Error of place in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item *i1, const Item *i2) {
	if(strcmp(i1->word, i2->word) < 0)
		return true;
	else
		return false;	
}

static bool ToRight(const Item *i1, const Item *i2) {
	int comp1;
	
	if(strcmp(i1->word, i2->word) > 0)
		return true;
	else
		return false;
}

static Trnode *MakeNode(const Item *pi) {
	Trnode *new_node;

	new_node = (Trnode *) malloc(sizeof(Trnode));
	if(new_node != NULL) {
		new_node->item = *pi;
		new_node->item.count = 1;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree) {
	Pair look;

	look.parent = NULL; 		// ссылка на предка
	look.child = ptree->root;	// ссылка на дочерний элемент = ссылка на корневой элемент
	
	if(look.child == NULL)		// если ссылка на дочерний элемент == NULL
		return look;
		
	while(look.child != NULL) {
		if(ToLeft(pi, &(look.child->item))) {	// если Item больше
			look.parent = look.child;
			look.child = look.child->left;
		} else if(ToRight(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->right;
		}
		else	// если элемент не расположен ни слева, ни справа, он должен быть таким же 
			break;	// look.child - это адрес узла, содержащего элемент
	}
	return look;
}

static void DeleteNode(Trnode **ptr) {
	// адрес родительского элемента, указывающего на целевой узел
	Trnode *temp;
	
	if((*ptr)->left == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	} else if((*ptr)->right == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	
	else {		// удаляемый узел имеет два дочерних узла
		// выяснение места присоединения правого поддерева
		for(temp = (*ptr)->left; temp->right != NULL; temp=temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
