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
	int sum = 0;
	for (list cur = l; cur != NULL; cur = cur->next) {
		sum += cur->value;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	node n3 = {3, NULL};
	node n2 = {2, &n3};
	node n1 = {1, &n2};
	list l  = &n1;

	assert (sum(l) == 6);

	printf("Passed!");

	return EXIT_SUCCESS;
}