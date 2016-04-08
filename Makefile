# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 16:10:30 by aperraul          #+#    #+#              #
#    Updated: 2016/04/07 14:09:10 by aperraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./sources/main.c \
	  ./sources/ft_check_line.c \
	  ./sources/get_map.c \
	  ./sources/ft_w3d_init.c \
	  ./sources/ft_pre_w3d.c \
	  ./sources/ft_wolf3d.c \
	  ./sources/draw_wolf3d.c \
	  ./sources/wolf3d_hook.c \
	  ./sources/wolf_events.c \
	  ./gnl/get_next_line.c \

OBJS = ./main.o \
	   ./ft_check_line.o \
	   ./get_map.o \
	   ./ft_w3d_init.o \
	   ./ft_pre_w3d.o \
	   ./ft_wolf3d.o \
	   ./draw_wolf3d.o \
	   ./wolf3d_hook.o \
	   ./wolf_events.o \
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
