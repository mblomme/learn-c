#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"

typedef struct _node {
	void * data;
	struct _node  * next;
} Node;

void freeNode (Node *);

void display(LinkedList * list, void (*displayData) (const void *));

void displayNode (Node *, void (*displayData) (const void *));

void freeList(LinkedList * list);


LinkedList * new_LinkedList() ;

Node * newNode(int n);

void populateList(LinkedList *);


void freeList(LinkedList * list) {
	if (list == NULL || list->head == NULL)
		return;

	freeNode(list->head);

	free(list->head);

	list->head = NULL;
}

void freeNode (Node * n) {
	if (n == NULL)
		return;

	if (n->next != NULL) {
		freeNode(n->next);
	}

	free(n->data);
	n->data = NULL;

	free(n->next);
	n->next = NULL;
}

void display(LinkedList * list, void (*displayData) (const void *)) {
	if (list == NULL || list->head == NULL)
		return;

	displayNode(list->head, displayData);
}

void displayNode(Node * node, void (*displayData) (const void *)) {
	if (node == NULL)
			return;

	int * intData = (int *) node->data;
	if (intData != NULL)
		displayData(intData);

	displayNode(node->next, displayData);
}

LinkedList * new_LinkedList() {
	LinkedList * l = (LinkedList *) malloc(sizeof(LinkedList));
	l->head = NULL;
	l->freeList = freeList;
	l->display = display;

	populateList(l);

	return l;
}

void populateList(LinkedList * list) {
	list->head = newNode(3);
	Node * mover = list->head;
	for (int i = 4; i < 20; i++) {
		mover->next = newNode(i);
		mover = mover->next;
	}
}

Node * newNode(int n) {
	int * data = (int *) malloc(sizeof(int));
	*data = n;

	Node * node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}
