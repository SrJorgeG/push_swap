/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:41:52 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/01 18:43:03 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *stack)
{
	t_nodo	*cur;
	t_nodo	*next;

	cur = stack->first_element;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

void	split_free(char **split)
{
	char	**aux;

	if (split)
	{
		aux = split;
		while (*aux)
			free(*aux++);
		free(split);
	}
}

void	error_exit(t_stack *stack_a, t_stack *stack_b, char **split)
{
	if (split)
		split_free(split);
	stack_free(stack_a);
	stack_free(stack_b);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}
