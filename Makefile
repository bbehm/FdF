# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 11:12:23 by bbehm             #+#    #+#              #
#    Updated: 2020/03/02 14:58:53 by bbehm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
GFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER_PATH = ./includes
HEADER_NAME = fdf.h
HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

SRCS_PATH = ./srcs
SRCS_NAME = main.c key_events.c drawing.c set_info.c support.c change_projection.c free.c
SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))

OBJ_PATH = ./srcs
OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME):	$(OBJ) $(HEADER)
				@make -C libft/
				@$(CC) $(CFLAGS) $(OBJ) $(GFLAGS) libft/libft.a -o $(NAME)

%.o:		%.c $(HEADER)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:		
				@rm -rf $(OBJ)
				@make -C libft clean

fclean:		clean
				@make -C libft fclean
				@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
