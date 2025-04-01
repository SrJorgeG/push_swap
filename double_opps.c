/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_opps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:41 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/01 18:21:10 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ss swap a y swap b a la vez.

void	ss(t_stack *stack1, t_stack *stack2)
{
	sx(stack1);
	sx(stack2);
}

// rr ra y rb al mismo tiempo.

void	rr(t_stack *stack1, t_stack *stack2)
{
	rx(stack1);	
	rx(stack2);	
}

// rrr rra y rrb al mismo tiempo.

void	rrr(t_stack *stack1, t_stack *stack2)
{
	rrx(stack1);	
	rrx(stack2);
}