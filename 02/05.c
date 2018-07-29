#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
Use a conditional expression to replace the if
in the following code.

How should each of the variables (ch and type)
be declared?
*/
int main(int argc, char *argv[]) {
	ch = getchar();
	if (isdigit(ch))
		type = "digit";
	else
		type = "non-digit";
	printf("'%c' is a %s\n", ch, type);

	return EXIT_SUCCESS;
}