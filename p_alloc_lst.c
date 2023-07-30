/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alloc_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <nbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:30:57 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/07/30 18:36:26 by nbeaufil         ###   ########.fr       */
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
	lst->addr = malloc(sz);
	return (lst);
}
