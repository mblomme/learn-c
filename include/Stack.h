/*
 * Stack.h
 *
 *  Created on: 26-mei-2016
 *      Author: infmblo
 */

#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_

	typedef void * T;

	struct _stack {
		void * internals;

		void (*push)(struct _stack *, T);

		T (*pop)(struct _stack *);

		void (*display)(struct _stack *);

		int (*getSize)(struct _stack *);
	};

	typedef struct _stack * Stack;

	Stack newStack(void (*deleteData) (T), void (*displayData) (const T));

	void push(Stack, T);

	T pop(Stack);

	void displayStack (Stack);

	int count(Stack);

	void deleteStack(Stack);

#endif /* INCLUDE_STACK_H_ */
