
typedef struct _linkedList {
	struct _node  * head;
	
	void (*display) (struct _linkedList *, void (displayData) (const void *));
	void (*freeList) (struct _linkedList *);
	void (*pushItem) (void * data);
	
} LinkedList;

LinkedList * new_LinkedList();

void initList(LinkedList *);
