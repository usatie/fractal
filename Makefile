# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 18:48:58 by susami            #+#    #+#              #
#    Updated: 2022/09/10 17:36:40 by susami           ###   ########.fr        #
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
			src/complex.c \
			src/color.c \
			src/mlx_util.c \
			src/ctx.c \
			src/ctx_put.c \
			src/ctx_put_config.c \
			src/ctx_put_config2.c \
			src/argparse.c \
			src/key_handler.c \
			src/mouse_handler.c \
			src/loop_handler.c \
			src/img.c \
			src/fractal.c \
			src/rect.c \
			src/mandelbrot.c \
			src/julia.c \
			src/barnsley.c \
			src/double_util.c \

OBJ_DIR		=	objs
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(LIBPATH) $(FRAMEWORK) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
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

debug: CFLAGS += -Weverything -Wno-padded -Wno-strict-prototypes -Wno-poison-system-directories -Wno-packed
debug: re
	norminette $(SRC_DIR) $(INCLUDE_DIR)
