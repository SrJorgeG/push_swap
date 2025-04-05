/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:16:20 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/05 04:37:05 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_contains(t_stack *stack, int num)
{
	t_nodo	*node;
	
	node = stack->first_element;
	while (node)
	{
		if (node->content == num)
			return (1);
		node = node->next;
	}
	return (0);
}

static int		str_isnum(char *str)
{
	if (!str || !*str)
		return (0);
	if ((*str == '-' || *str == '+') && !*++str)
		return (0);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

static void	check_split(t_stack *stack_a, t_stack *stack_b, char **split)
{
	long		num;
	char		**tmp;
	t_nodo		*aux;

	tmp = split;
	while (*split)
	{
		if (!str_isnum(*split))
			error_exit(stack_a, stack_b, tmp);
		num = ft_atol(*split);
		if (num < INT_MIN || num > INT_MAX)
			error_exit(stack_a, stack_b, tmp);
		if (ft_lst_contains(stack_a, (int)num))
			error_exit(stack_a, stack_b, tmp);
		aux = ft_lstnew((int) num);
		if (!aux)
			error_exit(stack_a, stack_b, tmp);
		ft_lstadd_back(stack_a, aux);
		split++;
		stack_a->stack_length++;
	}
	split_free(tmp);
}

t_stack		*parsing(int ac, char *av[], t_stack *a, t_stack *b)
{

	int			i;
	char		**args;	
	
	a->stack_length = 0;
	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	while (++i < ac)
		if (av[i][0])
		{
			args = ft_split(av[i], ' ');
			if (!args)
				error_exit(a, b, args);
			check_split(a, b, args);
		}
		else
			error_exit(a, b, args);
	return (a);
}
