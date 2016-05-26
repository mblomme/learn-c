
#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"

void displayData (const void * data) {
	const int * n = (const int *) data;
	printf("Value at p1: %d\n", *n);
}

int main() {

	LinkedList list = new_LinkedList();

	for (int i=25;i>=0; i--) {
		int * d = malloc(sizeof(int));
		*d = i;
		list->push(list, d);
	}

	list->display(list, displayData);

	list->clear(list);

	list->display(list, displayData);

	free(list);

	return 0;
}
