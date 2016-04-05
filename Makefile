# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 16:10:30 by aperraul          #+#    #+#              #
#    Updated: 2016/04/05 15:31:32 by aperraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./sources/main.c \
	  ./sources/get_map.c \
	  ./sources/ft_w3d_init.c \
	  ./gnl/get_next_line.c \

OBJS = ./main.o \
	   get_map.o \
	   ./ft_w3d_init.o \
	   ./get_next_line.o \

DRAW = ./Libdraw/draw.a

LIBFT = ./libft/libft.a

LIBMLX = ./libmlx/libmlx.a

LMLX = -lmlx

FRAMEWORK = $(LMLX) -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(DRAW) $(OBJS)
	$(CC) $(FLAGS) $(FRAMEWORK) $(OBJS) $(LIBFT) $(LIBMLX) $(DRAW) -o $(NAME)

$(OBJS): $(LIBFT) $(LIBMLX) $(DRAW)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	make -C ./libft/

$(LIBMLX):
	make -C ./libmlx/

$(DRAW):
	make -C ./Libdraw/

clean:
	$(RM) $(OBJS)
	make clean -C ./libft/
	make clean -C ./libmlx/
	make clean -C ./Libdraw/

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX) $(DRAW)

re: fclean all
