#include <stdlib.h>
#include <stdio.h>
#include "Bag.h"

// an unsorted array of
// pre-defined size MAX_BAG

#define MAX_BAG 1000

#define TRUE 1
#define FALSE 0

struct BagRep {
	int elements[MAX_BAG];
	int count;
};

Bag emptyBag() {
	Bag b = malloc(sizeof(struct BagRep));
	b->count = 0;
	return b;
}

void dropBag(Bag b) {
	free(b);

}
Bag BagCopy(Bag b) {
	return NULL;
}
int BagInsert(Bag b, int v) {
	if (b->count == MAX_BAG) {
		return TRUE;
	}
	b->elements[b->count] = v;
	b->count++;
	return FALSE;
}
void BagDelete(Bag b, int v) {
	int seen = 0;
	for (int i = 0; i < b->count; i++) {
		if (seen) {
			b->elements[i-1] = b->elements[i];
		} else if (b->elements[i] == v) {
			seen = 1;
		}
	}

	if (seen) {
		b->count--;
	}

}

// returns a count of how many times
// the value occurs in the bag
int BagMember(Bag b, int v) {
	int count = 0;
	for (int i=0; i < b->count; i++) {
		if (b->elements[i] == v) {
			count++;
		}
	}
	return count;
}
Bag BagUnion(Bag b1, Bag b2) {
	return NULL;
}
Bag BagIntersect(Bag b1, Bag b2) {
	return NULL;
}

// returns a count of the number
// of values in the bag
int BagNumElems(Bag b) {
	return b->count;
}

// returns a count of the number
// of distinct values in the bag
int BagNumUniq(Bag b) {
	return 0;
}
void showBag(Bag b) {

}
void readBag(FILE *stream, Bag b) {

}