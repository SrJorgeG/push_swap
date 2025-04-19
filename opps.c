/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:04:16 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/19 05:43:43 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
// pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío.
// pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b. No hace nada si a está vacío.

void	px(t_stack *stackX, t_stack *stack2, char c)
{
	t_nodo	*tmp;

	tmp = stack2->first_element;
	stack2->first_element = stack2->first_element->next;
	tmp->next = stackX->first_element;
	stackX->first_element = tmp;
	stackX->stack_length++;
	stack2->stack_length--;
	if(!c)
		return ;
	write(1, "p", 1);
	write(1, &c, 1);
}

// sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si hay uno o menos elementos.
// sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si hay uno o menos elementos.

void	sx(t_stack *stack, char c)
{
	t_nodo	*tmp;
	
	if (!stack->first_element || !stack->first_element->next)
		return ;
	tmp = stack->first_element;
	stack->first_element = stack->first_element->next;
	tmp->next = stack->first_element->next;
	stack->first_element->next = tmp;
	if(!c)
		return ;
	write(1, "p", 1);
	write(1, &c, 1);
}


// ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.
// rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición, de forma que el primer elemento se convierte en el último.

void	rx(t_stack *stack, char c)
{
	t_nodo	*aux;
	t_nodo	*tmp;
	
	if (stack->stack_length < 2)
		return ;
	aux = stack->first_element;
	//print_list(stack, "Stack A before rx");
	tmp = stack->first_element;
	stack->first_element = stack->first_element->next;
	while (aux->next)
		aux = aux->next;
	aux->next = tmp;
	tmp->next = NULL;
	if(!c)
		return ;
	write(1, "p", 1);
	write(1, &c, 1);
	//print_list(stack, "Stack A after rx");
}

// rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero.
// rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una posición, de forma que el último elemento se convierte en el primero.

void	rrx(t_stack *stack, char c)
{
	t_nodo	*aux;
	t_nodo	*tmp;
	
	
	if (stack->stack_length < 2)
		return ;
	//print_list(stack, "Stack A before rrx");
	aux = stack->first_element;
	tmp = stack->first_element;
	while (aux->next->next)
		aux = aux->next;
	tmp = aux->next;
	aux->next = NULL;
	tmp->next = stack->first_element;
	stack->first_element = tmp;
	if(!c)
		return ;
	write(1, "p", 1);
	write(1, &c, 1);
	//print_list(stack, "Stack A After rrx");
}
