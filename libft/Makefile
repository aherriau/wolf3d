# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherriau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:31:57 by aherriau          #+#    #+#              #
#    Updated: 2017/11/26 16:20:43 by aherriau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_strlen.c\
	  ft_atoi.c ft_itoa.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_strcpy.c\
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
	  ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
	  ft_lstmap.c ft_lstpush_back.c ft_lstpush_front.c ft_lstsize.c\
	  ft_lstlast.c ft_lstreverse.c ft_lstclear.c ft_sort_integer_table.c\
	  get_next_line.c ft_lst_at.c ft_tabdel.c

OBJ = $(SRC:.c=.o)

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@echo "$(green)Compilation finished: $(NAME)$(reset)"

%.o: %.c ./libft.h
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	@rm -f $(OBJ)
	@echo "$(green)Object files deleted: $(NAME)$(reset)"

fclean:
	@rm -f $(NAME)
	@echo "$(green)Executable file deleted: $(NAME)$(reset)"

re: fclean all
