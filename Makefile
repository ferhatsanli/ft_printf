NAME = libftprintf.a
TEST = testout
TESTC = main.c

SRC = ft_printf.c utils.c utils_x.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

test: $(NAME) $(TESTC:.c=.o)
	@$(CC) $(CFLAGS) $(OBJ) $(TESTC) $(LIBFT) -o $(TEST)
	@echo "--OUTPUT--"
	@./$(TEST)
	@echo "\n----------"
	@echo

.PHONY: all clean fclean re test
