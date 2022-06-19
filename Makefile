# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 18:48:58 by susami            #+#    #+#              #
#    Updated: 2022/06/19 19:03:36 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME		=	fractol
LIBS		=	-lmlx -lXext -lX11
LIBPATH		=	-Lminilibx-linux -lmlx -L/usr/X11R6/lib
INCLUDE		=	-Iinclude
FRAMEWORK	=	-framework OpenGL -framework AppKit
CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE)

SRCS		=	main.c
OBJS		=	$(SRCS:%.c=%.o)

all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(LIBPATH) $(FRAMEWORK) -o $(NAME)
