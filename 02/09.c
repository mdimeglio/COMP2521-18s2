#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
/*
1. there are no braces around the bodies of some for loops;
   does this matter?
2. what is the line of code sscanf(argv[1],"%d",&N); doing?
3. suggest an alternative for the sscanf(...) statement?
4. for each of the asserts ...
   * describe what error is being checked for and why
   * suggest a better error message than what you get
     from assert
5. what are the values of a[0] and a[1] during execution?
6. why don't the values of a[0] and a[1] matter?
7. what is the purpose of this program?
*/
int main(int argc, char *argv[])
{
	int i, j, *a;
	int N = 0;

	// initialisation
	assert(argc > 1);
	sscanf(argv[1], "%d", &N);
	assert(N > 0);
	a = malloc(N*sizeof(int));
	assert(a != NULL);
	for (i = 2; i < N; i++) a[i] = 1;

	// computation
	for (i = 2; i < N; i++) {
		if (a[i]) {
			for (j = i; i*j < N; j++) a[i*j] = 0;
		}
	}

	// results
	for (i = 2; i < N; i++) {
		if (a[i]) printf("%d\n",i);
	}
	exit(EXIT_SUCCESS);
}