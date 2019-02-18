# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behiraux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 14:04:26 by behiraux          #+#    #+#              #
#    Updated: 2019/02/05 16:57:39 by behiraux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE = libft.h

SRC = ft_strchr.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strlen.c\
	  ft_strnew.c\
	  ft_strsub.c\
	  ft_strjoin.c\

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@


all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
