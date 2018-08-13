typedef struct BagRep *Bag;

Bag emptyBag();
void dropBag(Bag);
Bag BagCopy(Bag);
// returns whether insert was successful
int BagInsert(Bag,int);


// Remove one copy of the value from the bag
// eg.
// If we start with the bag {1, 1, 1}
// and delete 1
// we get the bag {1, 1}
void BagDelete(Bag,int);

// returns a count of how many times
// the value occurs in the bag
int BagMember(Bag,int);
Bag BagUnion(Bag,Bag);
Bag BagIntersect(Bag,Bag);

// returns a count of the number
// of values in the bag
int BagNumElems(Bag);

// returns a count of the number
// of distinct values in the bag
int BagNumUniq(Bag);
void showBag(Bag);
void readBag(FILE *, Bag);