/*
 * hello.c
 *
 *  Created on: May 4, 2016
 *      Author: matthiasblomme
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"

void displayData (const void * data) {
	const int * n = (const int *) data;
	printf("Value at p1: %d\n", *n);
}

int main() {

	LinkedList * list = new_LinkedList();

	list->display(list, displayData);

	list->freeList(list);

	list->display(list, displayData);

	return 0;
}


