/*
 * Stack.c

 *
 *  Created on: 26-mei-2016
 *      Author: infmblo
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/Stack.h"
#include "../include/LinkedList.h"

#define GET_LIST(X) (LinkedList) X->internals

Stack newStack() {
	Stack stack = malloc(sizeof(struct _stack));

	stack->internals = newLinkedList();
	stack->push = push;
	stack->pop = pop;
	stack->count = count;
	stack->displayStack = displayStack;

	return stack;
}

void push(Stack stack, void * data) {
	LinkedList l = GET_LIST(stack);
	l->addAt(l, data, 0);
}

void * pop(Stack stack) {
	LinkedList l = GET_LIST(stack);

	if (stack->count(stack) == 0)
		return NULL;

	return l->deleteItem(l, 0);
}

void displayStack (Stack stack, void (*displayData)(const void *)) {
	LinkedList l = GET_LIST(stack);

	l->display(l, displayData);
}

void deleteStack(Stack stack) {
	deleteLinkedList(GET_LIST(stack));

	stack->internals = NULL;

	free(stack);
}

int count(Stack stack) {
	LinkedList l = GET_LIST(stack);
	return l->getSize(l);
}
