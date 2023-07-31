/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alloc_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <nbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:30:57 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/07/31 14:50:21 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "p_alloc.h"

void	lst_add_back(t_alloc_ptr *lst, t_alloc_ptr *new)
{
	t_alloc_ptr	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	tmp->next = new;
}

t_alloc_ptr	*new_node(size_t sz)
{
	t_alloc_ptr	*lst;

	lst = malloc(sizeof(t_alloc_ptr));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->size = sz;
	lst->addr = malloc(sz);
	return (lst);
}

void	free_elem(t_alloc_ptr *elem)
{
	if (elem)
	{
		free(elem->addr);
		free(elem);
	}
}

t_alloc_ptr	*remove_address(int index, t_alloc_ptr *lst)
{
	t_alloc_ptr	*new_lst;
	t_alloc_ptr	*past;

	if (!index)
	{
		new_lst = lst->next;
		free_elem(lst);
		return (new_lst);
	}
	new_lst = lst;
	while (index)
	{
		past = lst;
		lst = lst->next;
		index--;
	}
	past->next = lst->next;
	free_elem(lst);
	return (new_lst);
}
