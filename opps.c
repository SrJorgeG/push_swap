/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:04:16 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/20 17:52:59 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack *stackX, t_stack *stack2, char c)
{
	t_nodo	*tmp;

	tmp = stack2->first_element;
	stack2->first_element = stack2->first_element->next;
	tmp->next = stackX->first_element;
	stackX->first_element = tmp;
	stackX->stack_length++;
	stack2->stack_length--;
	if (!c)
		return ;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	sx(t_stack *stack, char c)
{
	t_nodo	*tmp;

	if (!stack->first_element || !stack->first_element->next)
		return ;
	tmp = stack->first_element;
	stack->first_element = stack->first_element->next;
	tmp->next = stack->first_element->next;
	stack->first_element->next = tmp;
	if (!c)
		return ;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rx(t_stack *stack, char c)
{
	t_nodo	*aux;
	t_nodo	*tmp;

	if (stack->stack_length < 2)
		return ;
	aux = stack->first_element;
	tmp = stack->first_element;
	stack->first_element = stack->first_element->next;
	while (aux->next)
		aux = aux->next;
	aux->next = tmp;
	tmp->next = NULL;
	if (!c)
		return ;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rrx(t_stack *stack, char c)
{
	t_nodo	*aux;
	t_nodo	*tmp;

	if (stack->stack_length < 2)
		return ;
	aux = stack->first_element;
	tmp = stack->first_element;
	while (aux->next->next)
		aux = aux->next;
	tmp = aux->next;
	aux->next = NULL;
	tmp->next = stack->first_element;
	stack->first_element = tmp;
	if (!c)
		return ;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
