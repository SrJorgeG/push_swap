/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:34 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/12/14 14:50:11 by jgomez-d         ###   ########.fr       */
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
	struct s_nodo	*next_node;
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

void	sx(t_nodo *stack);
void	px(t_nodo *stack, int content);
void	rx(t_nodo *stack);
void	rrx(t_nodo *stack);

// DOUBLE OPPS

void	ss(t_nodo *stack1, t_nodo *stack2);
void	rr(t_nodo *stack1, t_nodo *stack2);
void	rrr(t_nodo *stack1, t_nodo *stack2);






#endif