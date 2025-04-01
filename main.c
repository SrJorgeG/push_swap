#include "push_swap.h"

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
	long		number;
	char		**tmp;
	t_nodo		*new_node;

	tmp = split;
	while (*split)
	{
		if (!str_isnum(*split))
			error_exit(stack_a, stack_b, tmp);
		number = ft_atol(*split);
		if (number < INT_MIN || number > INT_MAX)
			error_exit(stack_a, stack_b, tmp);
		if (ft_lsti_find(stack_a, (int)number))
			error_exit(stack_a, stack_b, tmp);
		new_node = ft_lsti_newnode((int) number);
		if (!new_node)
			error_exit(stack_a, stack_b, tmp);
		new_node->index = *size;
		ft_lsti_addback(&(data->stack_a), new_node);
		split++;
		*size = *size + 1;
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
			
			
		}

	}
}