# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 18:48:58 by susami            #+#    #+#              #
#    Updated: 2022/09/26 20:58:07 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
# Variables #
#############

CC			=	cc
NAME		=	fractol

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a

LIBS		=	-lmlx -lXext -lX11 -lft -lm
MLX_DIR		=	minilibx-linux
MLX		=	$(MLX_DIR)/libmlx.a
LIBPATH		=	-L$(MLX_DIR) -L/usr/X11R6/lib -L$(LIBFTDIR)
INCLUDE_DIR	=	include
INCLUDES	=	-I$(INCLUDE_DIR) -I$(MLX_DIR) -I/usr/X11R6/include
CFLAGS		=	-Wall -Werror -Wextra

SRC_DIR		=	src
SRCS		=	src/color/instant_colors.c		\
				src/color/color.c		\
				src/img/img.c		\
				src/main.c		\
				src/hooks/loop_handler.c		\
				src/hooks/key_handler.c		\
				src/hooks/expose_handler.c		\
				src/hooks/mouse_handler.c		\
				src/hooks/close_window.c		\
				src/hooks/custom_hooks.c		\
				src/complex/complex.c			\
				src/complex/complex_iteration.c			\
				src/draw/win_to_complex.c			\
				src/draw/draw.c				\
				src/draw/normalize_speeds.c				\
				src/draw/mandelbrot.c				\
				src/draw/julia.c				\
				src/draw/barnsley.c				\
				src/draw/affine_iteration.c				\


OBJ_DIR		=	objs
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.d)
.PHONY: $(DEPS)

##########################
# Platform Compatibility #
##########################

# LINUX | OSX | ARM
UNAME_S := $(shell uname -s)
UNAME_P := $(shell uname -p)

# Linux
ifeq ($(UNAME_S),Linux)
	CFLAGS += -D LINUX
debug: CFLAGS += -Wno-conversion -Wno-double-promotion
debug: CC = clang
endif

# macos x86
ifeq ($(UNAME_S),Darwin)
	CFLAGS += -D OSX
	FRAMEWORK = -framework OpenGL -framework AppKit
debug: CFLAGS += -Wno-reserved-id-macro
endif

# macos ARM (m1/m2...)
ifneq ($(filter arm%, $(UNAME_P)),)
	CFLAGS += -D ARM
	FRAMEWORK = -framework OpenGL -framework AppKit
debug: CFLAGS += -Wno-poison-system-directories
endif

#################
# General rules #
#################

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(LIBPATH) $(FRAMEWORK) -o $(NAME)

clean:
	$(RM) -rf *.o *.out $(OBJ_DIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

debug: CFLAGS += -Weverything -Wno-padded -Wno-strict-prototypes -Wno-packed
debug: re norm

norm:
	norminette $(LIBFTDIR) $(SRC_DIR) $(INCLUDE_DIR)
	@echo "norminette OK :D"

.PHONY: all clean fclean re bonus debug norm
-include $(DEPS)
