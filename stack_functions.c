/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:28:23 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/12/14 14:45:27 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = *lst;
	if (*lst)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	else
		*lst = new;
}


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}


void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*aux;

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

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
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

t_stack	*initialize_stack(t_nodo )
{

}