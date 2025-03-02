# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 21:39:05 by ltcherep          #+#    #+#              #
#    Updated: 2025/02/27 19:22:09 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS_PARSING	=	srcs/parsing/parsing.c		\
					srcs/parsing/utils_parsing.c\

SRCS_MAIN		=	srcs/main/main.c			\
					srcs/main/annex.c			\

SRCS_IMAGE		=	srcs/image/image.c			\
					srcs/image/image_utils.c	\
					srcs/image/image_line.c		\

SRCS = $(SRCS_PARSING) $(SRCS_MAIN) $(SRCS_IMAGE)

OBJS = $(SRCS:.c=.o)
LDFLAGS	= -Lmlx -lbsd -lmlx -lXext -lX11
LDFLAG = ./libft/libft.a
FLAG = -Wall -Werror -Wextra -Ilibft -Imlx -Ilibft/get_next_line -I. -fsanitize=address -g3
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
