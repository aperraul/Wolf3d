# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/27 15:26:56 by aperraul          #+#    #+#              #
#    Updated: 2016/05/10 12:12:43 by aperraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = draw.a

SRCS = draw_line.c \
	   draw_pixel.c \
	   get_pixel.c \
	   ft_make_3dpt.c \
	   ft_make_line.c \
	   ft_make_pt.c \
	   ft_make_vector.c \
	   ft_init_matrix.c \
	   ft_apply_matrix.c \
	   ft_multiply_matrix.c \
	   make_matrix.c \
	   mlx_init.c \
	   new_image.c \
	   ft_del_tab_pts.c \
	   ft_clear_mlx.c \
	   ft_reset_img.c \
	   rgb_hexa_convert.c \
	   ft_make_ptll.c \
	   draw_flush_img.c

OBJS = draw_line.o \
	   draw_pixel.o \
	   get_pixel.o \
	   ft_make_3dpt.o \
	   ft_make_line.o \
	   ft_make_pt.o \
	   ft_make_vector.o \
	   ft_init_matrix.o \
	   ft_apply_matrix.o \
	   ft_multiply_matrix.o \
	   make_matrix.o \
	   mlx_init.o \
	   new_image.o \
	   ft_del_tab_pts.o \
	   ft_clear_mlx.o \
	   ft_reset_img.o \
	   rgb_hexa_convert.o \
	   ft_make_ptll.o \
	   draw_flush_img.o

FLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) :
	$(CC) $(FLAGS) -c $(SRCS)

clean :
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(LIBFT) $(LIBMLX)

re: fclean all
