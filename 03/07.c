// Read numbers from stdin; print their sum on stdout
 
#include <stdlib.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int n = 0;   // current value
	int sum = 0; // sum of values
 
	while (scanf("%d",&n) == 1)
		sum += n;
	printf("%d\n", sum);
	return EXIT_SUCCESS;
}
 