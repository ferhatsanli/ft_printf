NAME = libftprintf.a

TEST = testout

SRC = ft_printf.c  parselib.c  parser.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TEST)
	@echo "--OUTPUT--"
	@./$(TEST)
	@echo "\n----------"
	@rm $(TEST)
	@echo
	@fclean

.PHONY: all clean fclean re test
