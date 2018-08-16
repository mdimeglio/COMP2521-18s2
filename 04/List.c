#include <stdlib.h>
#include <assert.h>
#include "List.h"

struct node {
	int value;
	struct node *next;
};


void drop(List l) {
	if (! isEmpty(l)) {
		drop(tail(l));
		free(l);
	}
}

List map(int (*f)(int), List l) {
	if (isEmpty(l)) {
		return empty();
	} else {
		List newTail = map(f, tail(l));
		int newHead = (*f)(head(l));
		return cons(newHead, newTail);
	}
}


int foldr(int (*f)(int,int), int z, List l) {
	if (isEmpty(l)) {
		return z;
	} else {
		return (*f)(head(l), foldr(f, z, tail(l)));
	}
}

int one(int x) { return 1; }
int add(int x, int y) { return x+y; }

int length(List l) {
	List mapped = map(one, l);
	int length = foldr(add, 0, mapped);
	drop(mapped);
	return length;
}


// Other functions
List empty() {
	return NULL;
}

List cons(int v, List l) {
	struct node *n = malloc(sizeof(struct node));
	n->value = v;
	n->next = l;
	return n;
}

int head(List l) {
	assert(!isEmpty(l));
	return l->value;
}

List tail(List l) {
	return l->next;
}

int isEmpty(List l) {
	return l == NULL;
}