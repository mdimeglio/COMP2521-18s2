#include <stdlib.h>
#include <stdio.h>
#include "Bag.h"

// an unsorted array of
// pre-defined size MAX_BAG
typedef struct node node;

struct node {
	int value;
	node *next;
};

typedef struct BagRep {
	node *list;
} BagRep;

void dropBag(Bag b) {

}
Bag BagCopy(Bag b) {
	return NULL;
}
void BagInsert(Bag b, int v) {

}
void BagDelete(Bag b, int v) {

}

// returns a count of how many times
// the value occurs in the bag
int BagMember(Bag b, int v) {
	return 0;
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
	return 0;
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