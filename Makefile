# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 21:39:05 by ltcherep          #+#    #+#              #
#    Updated: 2025/02/19 21:40:17 by ltcherep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS_PARSING =

SRCS = $(SRCS_PARSING)

OBJS = $(SRCS:.c=.o)
FLAG = -Wall -Werror -Wextra -g3 -fsanitize=address
RM = rm -f
AR = ar rcs
CC = gcc

.c.o:
			$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MAKE)
			$(CC) $(FLAG) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(MAKE)
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE)
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean
