# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 17:00:40 by mfunakos          #+#    #+#              #
#    Updated: 2024/12/29 22:07:20 by miyuu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

# Directories
SRC_DIR = ./src
LIBFT_DIR = ./libft

# Source files
SRC_FILES = create_stack.c \
error_check.c \
free_stack.c \
ft_stacksize.c \
marge_move.c \
merge_operations.c \
merge_diff.c \
ps_atoi.c \
push_swap.c \
merge_sort.c \
sort_push.c \
sort_reverse_rotate.c \
sort_rotate.c \
sort_short_utils.c \
sort_short.c \
sort_swap.c


SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object files
OBJS = $(SRC:.c=.o)


# Libraries
LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
