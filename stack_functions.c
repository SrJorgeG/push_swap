/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:28:23 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/04/01 19:07:31 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FUNCION FIXEADA??? PARA FUNCIONAR EN PUSH SWAP

void	ft_lstadd_back(t_stack *lst, t_nodo *new)
{
	t_nodo	*aux;

	aux = lst->first_element;
	if (lst)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		lst->stack_length++;
	}
	else
	{
		lst = initialize_stack(new);
		if (!lst)
			return (NULL);
	}
}

// FUNCION FIXEADA??? PARA FUNCIONAR EN PUSH SWAP

void	ft_lstadd_front(t_stack *lst, t_nodo *new)
{
	if (!lst->first_element || !new)
		return ;
	new->next = lst->first_element;
	lst->first_element = new;
	lst->stack_length++;
}


void	ft_lstclear(t_nodo **lst, void (*del)(void*))
{
	t_nodo	*temp;
	t_nodo	*aux;

	aux = *lst;
	if (!aux)
		return ;
	while (aux)
	{
		temp = aux->next;
		del(aux->content);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
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

int		ft_lstsize(t_nodo *lst)
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

// FUNCION QUE INICIALIZA LA CABEZERA DE LA LISTA (T_STACK)

t_stack	*initialize_stack(t_nodo *head)
{
	t_stack	*newlst;

	if (!head)
		return (NULL);
	newlst = malloc(sizeof(t_stack));
	if (!newlst)
		return (NULL);
	newlst->first_element = head;
	newlst->stack_length = 1;
	return	(newlst);
}
