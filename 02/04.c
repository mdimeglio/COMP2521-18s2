#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
/*
Give an if statement equivalent to the
following switch statement:
*/
int main(int argc, char *argv[]) {
	char ch = 'c';

	assert(islower(ch));
	switch (ch) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("vowel"); break;
	default:
		printf("consonant"); break;
	}
	return EXIT_SUCCESS;
}