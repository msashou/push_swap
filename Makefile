# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/03 19:06:53 by rnoda             #+#    #+#              #
#    Updated: 2026/08/19 21:31:17 by rnoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRC = push_swap \
      ft_calloc \
      ft_strjoin \
      ft_split \
	  ft_strlen \
	  ft_memcmp \
	  ft_atoi \
	  ft_strdup \
	  ft_strlcpy \
	  is_num \
	  output_err \
	  parser \
	  attach_index \
	  simple_sort \
	  medium_sort \
	  complex_sort \
	  command_push \
	  command_reverse_rotate \
	  command_rotate \
	  command_swap \
	  compute_disorder \
	  record_op


SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re