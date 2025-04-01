/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:34 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/01 13:04:08 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_nodo
{
	int				content;
	size_t			correct_index;
	struct s_nodo	*next;
}	t_nodo;

typedef	struct s_head
{
	size_t	stack_length;
	t_nodo	*first_element;
}	t_stack;

// BASIC OPPS

t_nodo	*pop(t_nodo *stack);
void	push(t_nodo *stack, int content);

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

void	ft_lstadd_back(t_stack *lst, t_nodo *new);






#endif