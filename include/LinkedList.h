#ifndef LINKEDLIST_H_
	#define LINKEDLIST_H_

	typedef void * T;

	struct _linkedList {
		void * internals;

		void (*display) (struct _linkedList *);
		void (*clear) (struct _linkedList *);
		void (*add) (struct _linkedList *, T);
		void (*addAt) (struct _linkedList *, T, int);
		int (*getSize)(struct _linkedList *);
		T (*deleteItem) (struct _linkedList *, int);
	};

	typedef struct _linkedList * LinkedList;

	LinkedList newLinkedList(void (*deleteData) (T), void (*displayData) (const T));

	void deleteLinkedList(LinkedList);

	void initList(LinkedList);

	void add (LinkedList, T);
	
	int getSize(LinkedList);

	void display(LinkedList);

	void freeList(LinkedList);

	void addAt(LinkedList, T, int);

	T deleteItem (LinkedList, int);

#endif
