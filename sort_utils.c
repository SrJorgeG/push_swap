/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:36:47 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/20 17:49:30 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *stack)
{
	t_nodo	*current;
	int		min_index;

	current = stack->first_element;
	min_index = current->correct_index;
	while (current->next)
	{
		current = current->next;
		if (current->correct_index < min_index)
			min_index = current->correct_index;
	}
	return (min_index);
}

int	count_r(t_nodo *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->correct_index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

int	is_sorted(t_stack *stack)
{
	t_nodo	*tmp;

	tmp = stack->first_element;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	else if (stack_a->stack_length == 2)
		sx(stack_a, 'a');
	else if (stack_a->stack_length == 3)
		simple_sort(stack_a, stack_a->stack_length);
	else if (stack_a->stack_length <= 7)
		s_insertion_sort(stack_a, stack_b, stack_a->stack_length);
	else if (stack_a->stack_length > 7)
	{
		k_sort1(stack_a, stack_b, stack_a->stack_length);
		k_sort2(stack_a, stack_b, stack_b->stack_length);
	}
	else
		error_exit(stack_a, stack_b, NULL);
}
