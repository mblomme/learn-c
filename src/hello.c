
#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"
#include "../include/Stack.h"

void displayData (const void * data) {
	const int * n = (const int *) data;
	printf("Value at p1: %d\n", *n);
}

int main() {

//	LinkedList list = newLinkedList();
//
//	for (int i=0;i<=25; i++) {
//		int * d = malloc(sizeof(int));
//		*d = i;
//		list->add(list, d);
//	}
//
//	list->display(list, displayData);
//
//	list->clear(list);
//
//	list->display(list, displayData);
//
//	free(list->internals);
//
//	free(list);



	// Stack and linkedlist should be passed a deleteDataType function through the constructor

	// Make a type T = void *

	// What about namespaces in c?


	Stack s = newStack();

	printf("aantal: %d\n", s->count(s));

	for (int i=0;i<= 25; i++) {
			int * d = malloc(sizeof(int));
			*d = i;
			s->push(s, d);
	}

	s->displayStack(s, displayData);
	printf("aantal: %d\n", s->count(s));

//	for (int i=0;i<= 25; i++) {
//		void * data = s->pop(s);
//		free(data);
//		data = NULL;
//		printf("aantal: %d\n", s->count(s));
//	}

	deleteStack(s);



	return 0;
}
