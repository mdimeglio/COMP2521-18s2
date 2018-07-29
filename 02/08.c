#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct _node {
	int value;
	struct _node *next;
};

typedef struct _node node;
typedef node *list;  // pointer to first Node

int sum(list l) {
	return 0;
}

int main(int argc, char *argv[]) {
	node n3 = {3, NULL};
	node n2 = {2, &n3};
	node n1 = {1, &n2};
	list l  = &n1;

	assert (sum(l) == 6);

	return EXIT_SUCCESS;
}