#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char *numToDay(int n);

int main(int argc, char *argv[]) {
	puts(numToDay(0));
	return EXIT_SUCCESS;
}

/*
Suggest at least two alternative and more concise ways of
achieving the same result. Include the assert(...) in each case.

For each function, including the one above,
explain what would happen if the assert(...) was removed
and the function was invoked via numToDay(7).
*/
char *numToDay(int n) {
	assert(0 <= n && n <= 6);
	char *day = NULL;
	
	if (n == 0) {
		day = "Sun";
	}
	else if (n == 1) {
		day = "Mon";
	}
	else if (n == 2) {
		day = "Tue";
	}
	else if (n == 3) {
		day = "Wed";
	}
	else if (n == 4) {
		day = "Thu";
	}
	else if (n == 5) {
		day = "Fri";
	}
	else if (n == 6) {
		day = "Sat";
	}
	return day;
}