# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 17:07:32 by fsanli            #+#    #+#              #
#    Updated: 2024/11/14 19:25:31 by fsanli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# <<<VARIABLES>>>
TESTC = main.c
TESTOUT = test
SRC				=	\
				ft_atoi.c       ft_memchr.c     ft_split.c      ft_strncmp.c \
				ft_bzero.c      ft_memcmp.c     ft_strchr.c     ft_strnstr.c \
				ft_calloc.c     ft_memcpy.c     ft_strdup.c     ft_strrchr.c \
				ft_isalnum.c    ft_memmove.c    ft_striteri.c   ft_strtrim.c \
				ft_isalpha.c    ft_memset.c     ft_strjoin.c    ft_substr.c \
				ft_isascii.c    ft_putchar_fd.c ft_strlcat.c    ft_tolower.c \
				ft_isdigit.c    ft_putendl_fd.c ft_strlcpy.c    ft_toupper.c \
				ft_isprint.c    ft_putnbr_fd.c  ft_strlen.c \
				ft_itoa.c       ft_putstr_fd.c  ft_strmapi.c
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= libft.a

OBJS			= $(SRC:.c=.o)

all:			$(NAME)

# OBJ -> LIB
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

# Clean OBJs
clean:
				$(RM) $(OBJS) $(TESTOUT)

# Clean OBJs and LIB and test
fclean:			clean
				$(RM) $(NAME)

# Clean OBJs and LIB
re:				fclean $(NAME)

test:	fclean
				$(CFLAGS) = "$(CFLAGS) -I."
				$(CC) $(CFLAGS) $(SRC) $(TESTC) -o $(TESTOUT)
				@echo "\n\n"
				./$(TESTOUT)
				@echo "\n\n"
				@$(RM) $(TESTOUT)
				@make fclean

.PHONY:			all clean fclean re test
