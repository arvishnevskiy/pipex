# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 12:04:29 by kelisabe          #+#    #+#              #
#    Updated: 2022/03/04 13:47:15 by kelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c pars_pipex.c finder_path.c pipex_utils.c pipex_utils_split.c

HEADERS = pipex.h

OBJS = $(patsubst %.c, %.o, $(SRCS))

CC = gcc

RM = rm -rf

FLAGS = -Wall -Werror -Wextra -std=c99

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re