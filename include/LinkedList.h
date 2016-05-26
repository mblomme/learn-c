#ifndef LINKEDLIST_H_
	#define LINKEDLIST_H_
	struct _linkedList {
		void * internals;

		void (*display) (struct _linkedList *, void (*displayData) (const void *));
		void (*clear) (struct _linkedList *);
		void (*add) (struct _linkedList *, void *);
		void (*addAt) (struct _linkedList *, void *, int);
		int (*getSize)(struct _linkedList *);
	};

	typedef struct _linkedList * LinkedList;

	LinkedList newLinkedList();

	void initList(LinkedList);

	void add (LinkedList, void *);
	
	int getSize(LinkedList);

	void display(LinkedList , void (*displayData) (const void *));

	void freeList(LinkedList);

	void addAt(struct _linkedList *, void *, int);

#endif
