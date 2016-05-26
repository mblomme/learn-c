#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"
#include "../include/LinkedList_Private.h"

void freeList(LinkedList list) {
	Node * head = (Node *) getHead(list);

	if (head == NULL)
		return;

	freeNode(head);

	free(head);

	setHead(list, NULL);

	setSize(list, 0);
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

void display(LinkedList list, void (*displayData) (const void *)) {
	if (list == NULL)
		return;

	Node * head = (Node *) getHead(list);

	displayNode(head, displayData);
}

void displayNode(Node * node, void (*displayData) (const void *)) {
	if (node == NULL)
			return;

	int * intData = (int *) node->data;
	if (intData != NULL)
		displayData(intData);

	displayNode(node->next, displayData);
}

void push(LinkedList list, void * data) {
	Node * node = newNode(data);

	Node * head = (Node *) getHead(list);

	node->next = head;

	setHead(list, node);
	incrementSizeCount(list);
}

void add(LinkedList list, void * data) {

	Node * head = (Node *) getHead(list);

	if (head == NULL) {
		setHead(list,newNode(data));
		return;
	}

	Node * node = newNode(data);
	Node * mover = (Node *) getHead(list);
	while (mover->next != NULL)
		mover = mover->next;

	mover->next = node;
	incrementSizeCount(list);
}

void addAt(LinkedList list, void * data, int n) {
	if (n >= getSize(list))
		return;

	if (getSize(list)== 0) {
		add(list, data);
	}

	Node * node = newNode(data);
	Node * mover = (Node *) getHead(list);
	int index = 0;
	while (mover->next != NULL) {
		if (index == (n-1))
			break;
		mover = mover->next;
		index++;
	}

	if (index != (n-1)) {
		//EXCEPTION THROWING!!!
	}

	Node * tail = mover->next;
	mover->next = node;
	node->next = tail;

	incrementSizeCount(list);
}

int getSize(LinkedList list) {
	if (list == NULL || list->internals == NULL)
			return 0;

	Internals * i = (Internals *) list->internals;
	return i->size;
}

Node * getHead(LinkedList list) {
	if (list == NULL || list->internals == NULL)
		return NULL;

	Internals * i = list->internals;
	if (i->head == NULL)
		return NULL;

	return i->head;
}

void setHead(LinkedList list, Node * node) {
	if (list->internals == NULL) {
		list->internals = newInternals();
	}

	Internals * i = list->internals;
	i->head = node;
	incrementSizeCount(list);
}

LinkedList new_LinkedList() {
	LinkedList l = (LinkedList) malloc(sizeof(struct _linkedList));
	l->internals = newInternals();
	l->clear = freeList;
	l->display = display;
	l->push = push;
	l->add = add;
	l->addAt = addAt;
	l->getSize = getSize;

	return l;
}

Node * newNode(void * data) {
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}

Internals * newInternals() {
	Internals * i = malloc(sizeof(Internals));
	i->size = 0;
	i->head = NULL;
	return i;
}

int incrementSizeCount(LinkedList list) {
	setSize(list, getSize(list) + 1);
	return getSize(list);
}

int decrementSizeCount(LinkedList list) {
	setSize(list, getSize(list) - 1);
	return getSize(list);
}

void setSize(LinkedList list, int size) {
	Internals * i = list->internals;
	i->size = size;
}

