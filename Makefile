# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 18:48:58 by susami            #+#    #+#              #
#    Updated: 2022/07/24 12:12:55 by susami           ###   ########.fr        #
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

SRC_DIR		=	src
SRCS		=	src/main.c \
			src/mlx_playground.c
OBJ_DIR		=	objs
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(LIBPATH) $(FRAMEWORK) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $^ $(CFLAGS) -c -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) *.o *.out $(OBJ_DIR)/*.o
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all
