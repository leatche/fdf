# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 21:39:05 by ltcherep          #+#    #+#              #
#    Updated: 2025/02/22 14:02:54 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS_PARSING	= srcs/parsing/parsing.c	\

SRCS_OTHER		= srcs/main.c				\

SRCS = $(SRCS_PARSING) $(SRCS_OTHER)

OBJS = $(SRCS:.c=.o)
LDFLAGS	= -Lmlx -lbsd -lmlx -lXext -lX11
LDFLAG = ./libft/libft.a
FLAG = -Wall -Werror -Wextra -Ilibft -Imlx -Ilibft/get_next_line -I. -g3 -fsanitize=address
RM = @rm -f
AR = ar rcs
CC = gcc

.c.o:
			@$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@echo Compiling Libft
			@$(MAKE) -s -C ./libft
			@echo Compiling MLX
			@$(MAKE) -s -C ./mlx 2> /dev/null
			@echo Linking Objects
			@$(CC) $(FLAG) $(OBJS) $(LDFLAG) $(LDFLAGS) -o $(NAME)
			@echo Done!



all:		$(NAME)

clean:
			@echo Cleaning Libft
			@$(MAKE) clean -s -C ./libft
			@echo Cleaning MLX
			@$(MAKE) clean -s -C ./mlx
			@echo Cleaning Objects
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -s -C ./libft
			@echo Cleaning $(NAME)
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean
