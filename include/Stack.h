/*
 * Stack.h
 *
 *  Created on: 26-mei-2016
 *      Author: infmblo
 */

#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_
	#include "LinkedList.h"
	#define GET_LIST(X) (LinkedList) X

	struct _stack {
		void * internals;

		void (*push)(struct _stack *, void *);

		void * (*pop)(struct _stack *);

		void (*displayStack)(struct _stack *, void (*displayData) (const void *));

		int (*count)(struct _stack *);
	};

	typedef struct _stack * Stack;

	Stack newStack();

	void push(Stack, void *);

	void * pop(Stack);

	void displayStack (Stack, void (*displayData)(const void *));

	int count(Stack);

#endif /* INCLUDE_STACK_H_ */
