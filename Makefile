# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 21:39:05 by ltcherep          #+#    #+#              #
#    Updated: 2025/02/20 00:42:29 by ltcherep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS_PARSING =

SRCS = $(SRCS_PARSING)

OBJS = $(SRCS:.c=.o)
LDFLAGS	= -Lmlx -lbsd -lmlx -lXext -lX11
LDFLAG = ./libft/libft.a
FLAG = -Wall -Werror -Wextra -Ilibft -I. -g3 -fsanitize=address
RM = rm -f
AR = ar rcs
CC = gcc

.c.o:
			$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			$(CC) $(FLAG) $(OBJS) $(LDFLAG) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean
