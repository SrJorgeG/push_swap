/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:04:16 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/05 19:31:22 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
// pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío.
// pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b. No hace nada si a está vacío.

void	px(t_stack *stackX, t_stack *stack2)
{
	t_nodo	*tmp;
	
	//print_list(stackX, "Stack 1 before px");
	//print_list(stack2, "Stack 2 before px");

	tmp = stack2->first_element;
	stack2->first_element = stack2->first_element->next;
	tmp->next = stackX->first_element;
	stackX->first_element = tmp;
	stackX->stack_length++;
	stack2->stack_length--;
	//print_list(stackX, "Stack 1 before px");
	//print_list(stack2, "Stack 2 before px");
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
	//print_list(stack, "Stack A after rx");
}

// rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero.
// rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una posición, de forma que el último elemento se convierte en el primero.

void	rrx(t_stack *stack)
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
	//print_list(stack, "Stack A After rrx");
}
