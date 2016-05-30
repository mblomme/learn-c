
#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"
#include "../include/Stack.h"
#include <string.h>

#define BUFFER 50

typedef struct _person {
	char * firstName;
	char * lastName;
} Person;


void displayPerson (const T data) {
	const Person * n = (const Person *) data;
	printf("Naam: %s\t Voornaam:%s\n",  n->firstName, n->lastName);
}

void deletePerson (const T data) {
	Person * n = (Person *) data;
	free(n->firstName);
	free(n->lastName);
	n->firstName = NULL;
	n->lastName = NULL;
}

void displayData (const T data) {
	const int * n = (const int *) data;
	printf("Value at p1: %d\n", *n);
}

void deleteData (T data) {
	int * n = (int *) data;
	*n = 0;
}

Person * newPerson(char * firstName, char * lastName) {
	Person * p = malloc(sizeof(Person));

	char * fn = malloc(sizeof(char) * BUFFER);
	char * ln = malloc(sizeof(char) * BUFFER);

	strcpy(fn, firstName);
	strcpy(ln, lastName);

	p->firstName = fn;
	p->lastName = ln;

	return p;
}

int main() {

	Person * p1 = newPerson("Matthias", "Blomme");

	Person * p2 = newPerson("Hannelore", "Verhamme");

	Person * p3 = newPerson("Reinout", "Verhamme");

	Stack s = newStack(deletePerson, displayPerson);

	printf("aantal: %d\n", s->getSize(s));

	s->push(s, p1);
	s->push(s, p2);
	s->push(s, p3);

	s->display(s);
	printf("aantal: %d\n", s->getSize(s));

	deleteStack(s);

	return 0;
}
