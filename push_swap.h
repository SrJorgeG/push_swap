/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:34 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/20 17:48:13 by jgomez-d         ###   ########.fr       */
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
	int				correct_index;
	struct s_nodo	*next;
}	t_nodo;

typedef struct s_head
{
	int		stack_length;
	t_nodo	*first_element;
}	t_stack;

// SIMPLE OPPS

void	sx(t_stack *stack, char c);
void	px(t_stack *stackX, t_stack *stack2, char c);
void	rx(t_stack *stack, char c);
void	rrx(t_stack *stack, char c);

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

t_stack	*parsing(int ac, char *av[], t_stack *a, t_stack *b);
long	ft_atol(const char *str);

// FREE FUNCTIONS

void	stack_free(t_stack *stack);
void	split_free(char **split);
void	error_exit(t_stack *stack_a, t_stack *stack_b, char **split);

// SORT AND UTILS

int		is_rot_sort(t_stack *stack, int min_s_index);
void	simple_sort(t_stack *stack, int length);
void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length);
void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length);
void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
int		get_min_index(t_stack *stack);
int		count_r(t_nodo *stack, int index);
int		is_sorted(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);

void	swap(int *a, int *b);
void	correct_index_setter_2(t_stack *stack, int n, int *array);
void	correct_index_setter_1(t_stack *stack, int n);
int		ft_sqrt(int number);
//void	print_list(t_stack *stack, const char *stack_name);

#endif