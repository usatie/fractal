# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 18:48:58 by susami            #+#    #+#              #
#    Updated: 2022/07/05 09:37:42 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME		=	fractol

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a

LIBS		=	-lmlx -lXext -lX11 -lft
LIBPATH		=	-Lminilibx-linux -L/usr/X11R6/lib -L$(LIBFTDIR)
INCLUDE		=	-Iinclude
FRAMEWORK	=	-framework OpenGL -framework AppKit
CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE) -D XK_MISCELLANY -D XK_XKB_KEYS

SRCS		=	main.c
OBJS		=	$(SRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(LIBPATH) $(FRAMEWORK) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) *.o *.out
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all
