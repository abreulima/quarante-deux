#include "get_next_line.h"
#include <stdio.h>
int main()
{
    int fd;
    char *line;

    fd = open("hi.txt", O_RDONLY);
    line =  get_next_line(fd);
    printf("%s", line);
    free(line);
    close(fd);
    return (0);
}
