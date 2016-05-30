#ifndef  LINKEDLIST_PRV_H_
	#define LINKEDLIST_PRV_H_
	#include "LinkedList.h"

	typedef struct _internals {
		struct _node  * head;
		int size;
		void (*deleteData) (T data);
		void (*displayData) (const T);
	} Internals;

	typedef struct _node {
		T data;
		struct _node  * next;
	} Node;

	Node * getHead(LinkedList);

	void setHead(LinkedList, Node *);

	Internals * newInternals(void (*deleteData) (T data), void (*displayData) (const T));

	void freeNode (Node *, void (*deleteNodeData)(T));

	void displayNode (Node *, void (*displayData) (const T));

	Node * newNode(T);

	int incrementSizeCount(LinkedList);

	int decrementSizeCount(LinkedList);

	void setSize(LinkedList, int);

	T clearNode(Node *);

#endif
