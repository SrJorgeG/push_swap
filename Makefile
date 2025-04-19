# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/19 06:13:19 by jgomez-d          #+#    #+#              #
#    Updated: 2025/04/19 06:36:36 by jgomez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror -O3 
#-fsanitize=address,leak
LIB_DIR 	= libft
LIB_NAME 	= $(LIB_DIR)/libft.a
SRC			= double_opps.c free_functions.c main.c opps.c parsing.c sort.c sort_utils.c stack_functions.c
OBJ = $(SRC:.c=.o)

all: $(LIB_NAME) $(NAME)

$(LIB_NAME):
	@make -C $(LIB_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	@rm -f $(OBJ) 
	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME) 
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re