# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/03 19:06:53 by rnoda             #+#    #+#              #
#    Updated: 2026/08/15 19:27:20 by rnoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap \
      ft_calloc \
      ft_strjoin \
      ft_split \
	  ft_strlen \
	  ft_memcmp \
	  ft_itoa \
	  ft_atoi \
	  ft_strdup \
	  ft_strlcpy \
	  is_num \
	  output_err \
	  parser


SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re