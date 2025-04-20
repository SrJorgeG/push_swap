/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_opps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:41 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/20 17:53:38 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack1, t_stack *stack2)
{
	sx(stack1, 0);
	sx(stack2, 0);
	write(1, "ss", 2);
	write(1, "\n", 1);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	rx(stack1, 0);
	rx(stack2, 0);
	write(1, "rr", 2);
	write(1, "\n", 1);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	rrx(stack1, 0);
	rrx(stack2, 0);
	write(1, "rrr", 3);
	write(1, "\n", 1);
}
