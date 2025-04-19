/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_opps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:41 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/19 05:54:06 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack1, t_stack *stack2)
{
	sx(stack1, 'a');
	sx(stack2, 'b');
	write(1, "ss", 2);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	rx(stack1, 'a');	
	rx(stack2, 'b');	
	write(1, "rr", 2);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	rrx(stack1, 'a');	
	rrx(stack2, 'b');
	write(1, "rrr", 3);
}