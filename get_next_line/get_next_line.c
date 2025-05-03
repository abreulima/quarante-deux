#include "get_next_line.h"

char *ft_bzero (char *s)
{
    int i;

    i = 0;
    while (i < BUFFER_SIZE)
    {
        s[i] = 0;
        i++;
    }
    return (s);
}

char *get_next_line(int fd)
{
    char *line;
    char buffer;
    int res;
    int count;

    line = malloc(BUFFER_SIZE + 1);
    if (!line)
        return (NULL);
    ft_bzero(line);
    count = 0;
    while (1)
    {
        res = read(fd, &buffer, 1);
        if (res < 1)
        {
            if (count < 1)
                {
                    free(line);
                    return (NULL);
                }
            return (line);
        }
        else if (count >= BUFFER_SIZE - 1)
        {
            line[count] = '\0';
            return (line);
        }
        if (buffer == 0)
        {
             line[count] = '\0';
            return (line);
        }
        if (buffer == '\r')
            continue ;
        if (buffer == '\n')
        {
            line[count] = '\n';
            line[count + 1] = '\0';
            return (line);
        }
        line[count] = buffer;
        count++;
    }
    return (line);
}
