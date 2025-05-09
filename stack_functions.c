/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:28:23 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/20 18:00:39 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FUNCION FIXEADA??? PARA FUNCIONAR EN PUSH SWAP

void	ft_lstadd_back(t_stack *lst, t_nodo *new)
{
	t_nodo	*aux;

	if (!new || !lst)
		return ;
	aux = lst->first_element;
	if (!aux)
		lst->first_element = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}

// FUNCION FIXEADA??? PARA FUNCIONAR EN PUSH SWAP

void	ft_lstadd_front(t_stack *lst, t_nodo *new)
{
	if (!lst->first_element || !new)
		return ;
	new->next = lst->first_element;
	lst->first_element = new;
}

t_nodo	*ft_lstnew(int content)
{
	t_nodo	*lst;

	lst = (t_nodo *)malloc(sizeof(t_nodo));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

int	ft_lstsize(t_nodo *lst)
{
	t_nodo	*current;
	int		size;

	current = lst;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
