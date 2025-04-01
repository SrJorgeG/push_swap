#include "push_swap.h"

int	ft_lst_contains(t_stack *stack, int num)
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


int		str_isnum(char *str)
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

void	check_split(t_stack *stack_a, t_stack *stack_b, char **split)
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
	ft_free_split(tmp);
}

t_stack		*parsing(int ac, char *av[], t_stack *a, t_stack *b)
{

	int			i;
	char		**args;	
	
	i = 1;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	while (i < ac)
	{
		if (av[i][0])
		{
			args = ft_split(av[1], ' ');
			if (!args)
				error_exit(a, b, args);
			check_split(a, b, args);
		}
		else
			error_exit(a, b, args);
		i++;
	}
	return (a);
}