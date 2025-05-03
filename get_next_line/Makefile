CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
NAME = gnl

all: $(NAME)

$(NAME): get_next_line.o get_next_line_utils.o teste.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o

fclean: clean
