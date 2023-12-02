#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char    *s;

    fd = open("a.txt", O_RDONLY);
	printf ("%d\n", fd);
	s = get_next_line(fd);
	printf ("%s\n", s);

	/*while (s != 0)
    {
        s = get_next_line(fd);
        printf("%s", s);
    }*/
    return (0);
}
