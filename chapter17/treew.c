// function of tree's support 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "treew.h"

// ��������� ��� ������
typedef struct pair {
	Trnode *parent;
	Trnode *child;
} Pair;

// ��������� ��������� �������
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (* pfun) (Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);

// ����������� �������
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
		return false;		// ��������������� �������
	}
	
	// ���� ����� ��� �������
	if ((seek = SeekItem(pi, ptree)).child != NULL) {	// ���������� ����� �������
		// ������� pi ������, �� ��� �����
		//fprintf(stderr, "Trying of adding of doubled element\n");
		//return false;		
		seek.child->item.count++;
		return true;
	}
	
	new_node = MakeNode(pi);	// ��������� �� ����� ����
	if (new_node == NULL) {
		fprintf(stderr, "Cannot create node\n");
		return false;			// ��������������� �������
	}
	
	// �������� �������� ������ ����
	ptree->size++;
	if(ptree->root == NULL)				// ������ 1: ������ ������
		ptree->root = new_node;			// ����� ���� - ������ ������
	else								// ������ 2: ������ �� ������ 
		AddNode(new_node, ptree->root);	// ���������� ���� � ������
	return true;						// ������� � ������ ������
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
	if(look.parent == NULL)		// �������� ��������� ��������
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

// ��������� ������
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
		if(root->left == NULL)				// ������ ���������
			root->left = new_node;			// ������� �������� ���� ����
		else
			AddNode(new_node, root->left);	// ����� ���������� ���������
	}
	else if (ToRight(&new_node->item, &root->item)) {
		if(root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	} else {								// ��������� �� �����������
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

	look.parent = NULL; 		// ������ �� ������
	look.child = ptree->root;	// ������ �� �������� ������� = ������ �� �������� �������
	
	if(look.child == NULL)		// ���� ������ �� �������� ������� == NULL
		return look;
		
	while(look.child != NULL) {
		if(ToLeft(pi, &(look.child->item))) {	// ���� Item ������
			look.parent = look.child;
			look.child = look.child->left;
		} else if(ToRight(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->right;
		}
		else	// ���� ������� �� ���������� �� �����, �� ������, �� ������ ���� ����� �� 
			break;	// look.child - ��� ����� ����, ����������� �������
	}
	return look;
}

static void DeleteNode(Trnode **ptr) {
	// ����� ������������� ��������, ������������ �� ������� ����
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
	
	else {		// ��������� ���� ����� ��� �������� ����
		// ��������� ����� ������������� ������� ���������
		for(temp = (*ptr)->left; temp->right != NULL; temp=temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
