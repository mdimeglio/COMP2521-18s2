#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TRUE  1
#define FALSE 0

// Pre:
// - a[] is a valid pointer to the start of an array of ints
// - n is a positive int indicating how many elements in a[]
// Post:
// - return value = ∀ i ∈ {0..n-2} ( a[i] ≤ a[i+1] )
int isSorted(int *a, int n) {
	return TRUE;
}

/*
What while loop is equivalent
to the following for statement?
*/
int main(int argc, char *argv[]) {
	int a[10] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
	assert(isSorted(a, 10));

	int b[5] = {1, 2, 1, 2, 3};
	assert(!isSorted(b, 5));

	return EXIT_SUCCESS;
}