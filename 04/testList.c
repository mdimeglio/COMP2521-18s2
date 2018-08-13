#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "List.h"

void testMap();
void testFoldr();
void testLength();

int main(int argc, char *argv[]) {
	testMap();
	testFoldr();
	testLength();
	return EXIT_SUCCESS;
}

// Trace sequence of function calls on
// map([1,3,5,7],square)
int square(int x) { return x*x; }

void testMap() {
	List l1 = cons(1, cons(3, cons(5, cons(7, empty()))));

	printf("Testing map(square, [1,3,5,7]) == [1, 9, 25, 49]...");
	List l2 = map(square, l1);

	assert(head(l2) == 1);
	assert(head(tail(l2)) == 9);
	assert(head(tail(tail(l2))) == 25);
	assert(head(tail(tail(tail(l2)))) == 49);
	assert(isEmpty(tail(tail(tail(tail(l2))))));

	assert(head(l1) == 1);
	assert(head(tail(l1)) == 3);
	assert(head(tail(tail(l1))) == 5);
	assert(head(tail(tail(tail(l1)))) == 7);
	assert(isEmpty(tail(tail(tail(tail(l1))))));

	printf("passed!\n");

	drop(l1);
	drop(l2);
}

// Trace the sequence
// foldr([2, 3, 4], sub, 5);
// == sub(2, sub(3, sub(4, 5)))
// == sub(2, sub(3, -1))
// == sub(2, 4)
// == -2

int sub(int x, int y) { return x-y; }
 
void testFoldr() {
	List l = cons(2, cons(3, cons(4, empty())));

	printf("Testing foldr([2,3,4],sub, 5) == -2...");
	assert(foldr(sub, 5, l) == -2);
	printf("passed!\n");

	drop(l);
}

void testLength() {
	List l = cons(1, cons(3, cons(5, cons(7, empty()))));

	printf("Testing length([1,3,5,7])...");
	assert(length(l) == 4);
	printf("passed!\n");

	drop(l);
}

