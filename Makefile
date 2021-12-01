# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajung <ajung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:25:13 by ajung             #+#    #+#              #
#    Updated: 2021/12/01 15:28:16 by ajung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	get_next_line_utils.c \
		get_next_line.c \
		

OBJS = $(SRCS:.c=.o)

BONUS =

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I

NAME = libftprintf.a

%.o: %.c
	gcc -Wall -Werror -Wextra -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -f $(NAME)

re: 		fclean $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:		all clean fclean re bonus