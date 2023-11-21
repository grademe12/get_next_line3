#include <stdio.h>
#include <stdlib.h>

int main()
{
	static char *ptr;

	printf ("%p\n", ptr);
	return (0);
}
