# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 09:19:52 by ssettle           #+#    #+#              #
#    Updated: 2019/05/15 00:04:01 by rsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_DIR = ./sources/
INC_DIR = ./includes/

SRCS = $(addprefix $(SRC_DIR),$(SOURCES))
INC = $(addprefix -I,$(INC_DIR))

SOURCES = main.c \
	figure_it_out.c \
	im_the_map.c \
	legit_check.c \
	love_and_piece.c \
	reading_rainbow.c \
	colors.c \

OBJECTS = $(addprefix $(SRC_DIR),$(SOURCES:.c=.o))

INCLUDES = ft_fillit.h

FLAGS = -Wall -Werror -Wextra -g

LIBFT = -lm -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C ./libft
	@echo Libft made!
	@gcc -o $(NAME) $(FLAGS) $(SRCS) $(LIBFT)
	@echo Project made!

clean:
	@make -C ./libft clean
	@rm -rf $(OBJECTS)
	@echo Project cleaned!

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)
	@echo Project fcleaned!

re: clean all

.PHONY: make, all, clean, fclean, re, test
