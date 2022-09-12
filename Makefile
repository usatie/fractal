# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 18:48:58 by susami            #+#    #+#              #
#    Updated: 2022/09/12 16:25:21 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME		=	fractol

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a

LIBS		=	-lmlx -lXext -lX11 -lft -lm
MLX_DIR		=	minilibx-linux
MLX		=	$(MLX_DIR)/mlx.a
LIBPATH		=	-L$(MLX_DIR) -L/usr/X11R6/lib -L$(LIBFTDIR)
INCLUDE_DIR	=	include
INCLUDE		=	-I$(INCLUDE_DIR) -I$(MLX_DIR) -I/usr/X11R6/include
CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE)

# LINUX | OSX | ARM
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -D LINUX
else
	FRAMEWORK = -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME_S),Darwin)
	CFLAGS += -D OSX
endif

UNAME_P := $(shell uname -p)
ifneq ($(filter arm%, $(UNAME_P)),)
	CFLAGS += -D ARM
endif

SRC_DIR		=	src
SRCS		=	src/main.c \
				src/double_util.c \
				src/ctx/ctx.c \
				src/ctx/ctx_util.c \
				src/ctx/ctx_put.c \
				src/ctx/ctx_put_config.c \
				src/ctx/ctx_put_config2.c \
				src/argparse/argparse.c \
				src/argparse/argparse_flag.c \
				src/mlx/color.c \
				src/mlx/mlx_util.c \
				src/mlx/key_handler.c \
				src/mlx/mouse_handler.c \
				src/mlx/loop_handler.c \
				src/mlx/img.c \
				src/mlx/rect.c \
				src/fractal/complex.c \
				src/fractal/fractal.c \
				src/fractal/mandelbrot.c \
				src/fractal/julia.c \
				src/fractal/barnsley.c \
				src/fractal/speeds.c \

OBJ_DIR		=	objs
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(LIBPATH) $(FRAMEWORK) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $$(dirname $@)
	$(CC) $^ $(CFLAGS) -c -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) *.o *.out $(OBJ_DIR)/*.o
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

# x86 mac
ifeq ($(UNAME_S),Darwin)
debug: CFLAGS += -Weverything -Wno-padded -Wno-strict-prototypes -Wno-packed -Wno-reserved-id-macro
endif

# ARM mac
ifneq ($(filter arm%, $(UNAME_P)),)
debug: CFLAGS += -Weverything -Wno-padded -Wno-strict-prototypes -Wno-packed -Wno-poison-system-directories
endif

debug: re
	norminette $(SRC_DIR) $(INCLUDE_DIR)
