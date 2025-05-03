#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_chunk
{
    struct s_chunk*     next;
    char                *string;
}                       t_chunk;

char *get_next_line(int fd);

#endif
