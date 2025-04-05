/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:04:16 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/05 04:38:01 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
// pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío.
// pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b. No hace nada si a está vacío.

void	px(t_stack *stackX, t_stack *stack2)
{
	t_nodo	*tmp;
	
	tmp = stack2->first_element;
	tmp->next = stackX->first_element;
	stackX->first_element = tmp;
	stackX->stack_length++;
	stack2->first_element = stack2->first_element->next;
	stack2->stack_length--;
}

// sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si hay uno o menos elementos.
// sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si hay uno o menos elementos.

void	sx(t_stack *stack)
{
	t_nodo	*tmp;
	
	if (!stack->first_element || !stack->first_element->next)
		return ;
	tmp = stack->first_element;
	stack->first_element = stack->first_element->next;
	tmp->next = stack->first_element->next;
	stack->first_element->next = tmp;
}


// ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.
// rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición, de forma que el primer elemento se convierte en el último.

void	rx(t_stack *stack)
{
	t_nodo	*tmp;
	
	tmp = stack->first_element;
	ft_lstadd_back(stack, tmp);
	stack->first_element = stack->first_element->next;
}

// rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero.
// rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una posición, de forma que el último elemento se convierte en el primero.

void	rrx(t_stack *stack)
{
	t_nodo	*aux;
	t_nodo	*tmp;
	
	aux = stack->first_element;
	tmp = stack->first_element;
	while (aux->next)
	{
		if (tmp->next->next)
			tmp = tmp->next;
		aux = aux->next;
	}
	tmp->next = NULL;
	ft_lstadd_front(stack, aux);
}
