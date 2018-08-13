#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Bag.h"

void testBagDelete1();

int main (int argc, char *argv[]) {
	testBagDelete1();

	printf("All tests passed!\n");
	return EXIT_SUCCESS;
}

void testBagInsert1() {
	printf("Testing BagInsert({}, 1)...");
	Bag b = emptyBag();
	BagInsert(b, 1);

	assert(BagNumElems(b) == 1);
	assert(BagMember(b, 1) == 1);
	showBag(b);
	printf("passed!\n");
}


void testBagDelete1() {
	printf("Testing BagDelete({1, 1, 2}, 1)...");
	Bag b = emptyBag();
	BagInsert(b, 1);
	BagInsert(b, 2);
	BagInsert(b, 1);

	BagDelete(b, 1);

	assert(BagNumElems(b) == 2);
	printf("BagMember(b, 1) == %d", BagMember(b, 1));
	assert(BagMember(b, 1) == 1);
	assert(BagMember(b, 2) == 1);
	assert(BagMember(b, 3) == 0);
	printf("passed!\n");

}
