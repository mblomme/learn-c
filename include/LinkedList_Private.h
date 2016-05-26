#ifndef  LINKEDLIST_PRV_H_
	#define LINKEDLIST_PRV_H_
	#include "LinkedList.h"

	typedef struct _internals {
		struct _node  * head;
		int size;
	} Internals;

	typedef struct _node {
		void * data;
		struct _node  * next;
	} Node;

	Node * getHead(LinkedList);

	void setHead(LinkedList, Node *);

	Internals * newInternals();

	void freeNode (Node *);

	void displayNode (Node *, void (*displayData) (const void *));

	Node * newNode(void *);

	int incrementSizeCount(LinkedList);

	int decrementSizeCount(LinkedList);

	void setSize(LinkedList, int);

#endif
