NAME = libftprintf.a
TEST = testout

SRC = ft_printf.c  parselib.c  parser.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(TEST)
	@echo "--OUTPUT--"
	@./$(TEST)
	@echo "\n----------"
	@rm $(TEST)
	@echo
	@fclean

.PHONY: all clean fclean re test
