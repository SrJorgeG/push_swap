/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:34 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/01 20:41:40 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_nodo
{
	int				content;
	unsigned int	correct_index;
	struct s_nodo	*next;
}	t_nodo;

typedef	struct s_head
{
	size_t	stack_length;
	t_nodo	*first_element;
}	t_stack;

// SIMPLE OPPS

void	sx(t_stack *stack);
void	px(t_stack *stackX, t_stack *stack2);
void	rx(t_stack *stack);
void	rrx(t_stack *stack);

// DOUBLE OPPS

void	ss(t_stack *stack1, t_stack *stack2);
void	rr(t_stack *stack1, t_stack *stack2);
void	rrr(t_stack *stack1, t_stack *stack2);

// STACK FUNCTIONS

t_nodo	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack *lst, t_nodo *new);
void	ft_lstadd_front(t_stack *lst, t_nodo *new);
int		ft_lstsize(t_nodo *lst);

// PARSING FUNCTIONS

long	ft_atol(const char *str);

// FREE FUNCTIONS

void	stack_free(t_stack *stack);
void	split_free(char **split);
void	error_exit(t_stack *stack_a, t_stack *stack_b, char **split);

// MAIN

int		str_isnum(char *str);
int		ft_lst_contains(t_stack *stack, int num);
void	check_split(t_stack *stack_a, t_stack *stack_b, char **split);
t_stack	*parsing(int ac, char *av[], t_stack *a, t_stack *b);



#endif