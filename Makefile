NAME = test
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g -fsanitize=address,undefined

SRC = bits.c test.c
OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

%.o: %.c bits.h
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(NAME)

clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re