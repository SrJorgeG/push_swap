/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:35:51 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/20 18:00:27 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rot_sort(t_stack *stack, int min_s_index)
{
	int	a;
	int	b;
	int	c;

	(void)min_s_index;
	a = stack->first_element->content;
	b = stack->first_element->next->content;
	c = stack->first_element->next->next->content;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}

void	simple_sort(t_stack *stack, int length)
{
	int		min_s_index;
	int		r;

	if (is_sorted(stack))
		return ;
	min_s_index = get_min_index(stack);
	r = count_r(stack->first_element, min_s_index);
	if (is_rot_sort(stack, min_s_index))
	{
		if (r < length - r)
			rx(stack, 'a');
		else
			rrx(stack, 'a');
	}
	else
	{
		sx(stack, 'a');
		if (is_sorted(stack))
			return ;
		if (r < length - r)
			rx(stack, 'a');
		else
			rrx(stack, 'a');
	}
}

void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	min_index;
	int	iter;
	int	n;

	iter = 0;
	n = length;
	while (iter++ < n - 3)
	{
		min_index = get_min_index(stack_a);
		if (count_r(stack_a->first_element, min_index) <= n - min_index
			- count_r(stack_a->first_element, min_index))
			while (stack_a->first_element->correct_index != min_index)
				rx(stack_a, 'a');
		else
			while (stack_a->first_element->correct_index != min_index)
				rrx(stack_a, 'a');
		if (is_sorted(stack_a) && stack_b->stack_length == 0)
			return ;
		px(stack_b, stack_a, 'b');
		length--;
	}
	simple_sort(stack_a, length);
	iter = 0;
	while (iter++ < n - 3)
		px(stack_a, stack_b, 'a');
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->first_element)
	{
		if (stack_a->first_element->correct_index <= i)
		{
			px(stack_b, stack_a, 'b');
			i++;
		}
		else if (stack_a->first_element->correct_index <= i + range)
		{
			px(stack_b, stack_a, 'b');
			rx(stack_b, 'b');
			i++;
		}
		else
			rx(stack_a, 'a');
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b->first_element, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->first_element->correct_index != length - 1)
				rx(stack_b, 'b');
			px(stack_a, stack_b, 'a');
			length--;
		}
		else
		{
			while (stack_b->first_element->correct_index != length - 1)
				rrx(stack_b, 'b');
			px(stack_a, stack_b, 'a');
			length--;
		}
	}
}
