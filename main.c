#include "push_swap.h"

// void	print_list(t_stack *stack, const char *stack_name)
// {
// 	t_nodo		*current;
// 	int					position;

// 	position = 0;
// 	if (!stack)
// 	{
// 		printf("%s: (vacío)\n", stack_name);
// 		return ;
// 	}
// 	current = stack->first_element;
// 	printf("═════ %s ═════\n", stack_name);
// 	printf("Pos │ Valor  │ Índice\n");


// 	while (current != NULL)
// 	{
// 		printf("%-3d │ %-6d │ %-6u\n", position++,
// 			current->content, current->correct_index);
// 		current = current->next;
// 	}
// 	printf("═════════════════════\n\n");
// }

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	correct_index_setter_2(t_stack *stack, int n, int *array)
{
	int	i;
	int	j;
	t_nodo *aux;

	i = 0;
	while (++i <= n - 1)
	{
		j = i + 1;
		while (--j > 0 && array[j - 1] > array[j])
			swap(&(array[j]), &(array[j - 1]));
	}
	aux = stack->first_element;
	while (aux)
	{
		i = 0;
		while (i < n && aux->content != array[i])
			i++;
		aux->correct_index = i;
		aux = aux->next;
	}
	free(array);
}

void	correct_index_setter_1(t_stack *stack, int n)
{
	int	i;
	int	*array;
	t_nodo *current;

	i = 0;
	array = ft_calloc(n, sizeof(int));
	if (!array)
		error_exit(stack, NULL, NULL);
	current = stack->first_element;
	while (current)
	{
		array[i++] = current->content;
		current = current->next;
	}
	correct_index_setter_2(stack, n, array);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

int	main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;

	a = ft_calloc(1 , sizeof(t_stack));
	if (!a)
		error_exit(a, NULL, NULL);
	b = ft_calloc(1 , sizeof(t_stack));
	if (!b)
		error_exit(a, b, NULL);
	if (ac < 2) 
		error_exit(a, b, NULL);
	parsing(ac, av, a, b);
	correct_index_setter(a, a->stack_length);
	sort(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
