# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 16:10:30 by aperraul          #+#    #+#              #
#    Updated: 2016/06/06 14:07:48 by aperraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./sources/main.c \
	  ./sources/ft_check_line.c \
	  ./sources/ft_check_map.c \
	  ./sources/get_map.c \
	  ./sources/ft_w3d_init.c \
	  ./sources/ft_pre_w3d.c \
	  ./sources/ft_wolf3d.c \
	  ./sources/draw_wolf3d.c \
	  ./sources/wolf3d_hook.c \
	  ./sources/event_move.c \
	  ./sources/wolf_events.c \
	  ./sources/wolf_portal.c \
	  ./sources/portal_set.c \
	  ./sources/portal_move.c \
	  ./sources/load_w3d_textures.c \
	  ./sources/draw2_wolf3d.c \
	  ./sources/ft_wall_side.c \
	  ./gnl/get_next_line.c \

OBJS = ./main.o \
	   ./ft_check_line.o \
	   ./ft_check_map.o \
	   ./get_map.o \
	   ./ft_w3d_init.o \
	   ./ft_pre_w3d.o \
	   ./ft_wolf3d.o \
	   ./draw_wolf3d.o \
	   ./wolf3d_hook.o \
	   ./wolf_events.o \
	   ./event_move.o \
	   ./wolf_portal.o \
	   ./portal_set.o \
	   ./portal_move.o \
	   ./load_w3d_textures.o \
	   ./draw2_wolf3d.o \
	   ./ft_wall_side.o \
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
