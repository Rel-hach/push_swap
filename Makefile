# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 18:49:06 by rel-hach          #+#    #+#              #
#    Updated: 2022/04/10 17:19:57 by rel-hach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

CC = cc  

CFLAGS = -Wall -Werror -Wextra

SRC = Push_swap_src/main_function.c \
			Push_swap_src/lists.c \
			Push_swap_src/rotate_actions.c \
			Push_swap_src/reverse_rotate_actions.c \
			Push_swap_src/utils.c \
			Push_swap_src/utils2.c \
			Push_swap_src/utils3.c \
			Push_swap_src/utils4.c \
			Push_swap_src/swap_push_actions.c \
			Push_swap_src/stack_is_sorted.c \
			Push_swap_src/sort_few_number.c \
			Push_swap_src/ft_sort_several_numbers.c \
			Push_swap_src/ft_put_index.c \
			Push_swap_src/check_validity_and_build_stack.c \

SRC_BONUS = Checker_src/checker.c \
				Checker_src/reverse_rotate_actions_bonus.c \
				Checker_src/rotate_actions_bonus.c \
  				Checker_src/swap_push_actions_bonus.c \
   				Checker_src/utils.c \
				Checker_src/utils2.c \
				Checker_src/utils3.c \
				Checker_src/utils4.c \
				Checker_src/stack_is_sorted.c \
				Checker_src/lists.c \
				Checker_src/check_validity_and_build_stack.c \
				Checker_src/gnl.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)


all : $(PUSH_SWAP)
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	
$(PUSH_SWAP) : $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(PUSH_SWAP)
	
bonus : $(OBJ_BONUS)
		@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(CHECKER)
	
clean :
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER) 

re : fclean all

.PHONY : clean fclean re
