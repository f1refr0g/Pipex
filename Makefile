# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 14:03:16 by abeaudet          #+#    #+#              #
#    Updated: 2023/02/18 12:35:42 by abeaudet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex


#include
LIB_PATH = includes/libft
LIBFT = $(LIB_PATH)/libft.a
MLX_PATH = includes/MLX42
MLX = $(MLX_PATH)/libmlx42.a $(MLX_PATH)/lib/lib-x86_64/libglfw3.a
MLX_FLAGS = -framework Cocoa -framework OpenGl -framework IOKit
SFLAG = -fsanitize=address
 

# source files
S = srcs/
SRCS_FILES = pipex.c \
			pipex_utils.c \


			
SRCS = $(addprefix $S, $(SRCS_FILES))

OBJS = $(SRCS:%.c=%.o)

O = /objs
$O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

BONUS_OBJS = $(BONUS:.c=.o)

HEADER = $(SRC_PATH)pipex.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra



	
all: libinit  $(NAME)

$(NAME):  $(OBJS)
	@$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBFT)
			
libinit: 
		@echo "$R creation de la libft...$W"
		@$(MAKE) -s -C ./includes/libft
		@echo "$G libft created!$W"

clean:
	@rm -f $(OBJS)
	@echo "$B Cleaning complete.$W"
	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./includes/libft
	
re: fclean all

# COLORS
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)