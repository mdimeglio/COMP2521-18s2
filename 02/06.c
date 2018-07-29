#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
What while loop is equivalent
to the following for statement?
*/
int main(int argc, char *argv[]) {
	for (ch = getchar(); ch != EOF; ch = getchar()) {
		putchar(ch);
	}

	return EXIT_SUCCESS;
}