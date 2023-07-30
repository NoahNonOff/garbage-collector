/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <nbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:34:34 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/07/30 18:38:34 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "p_alloc.h"

t_alloc_ptr	*addr_save(t_alloc_ptr *ptr, int code)
{
	static t_alloc_ptr	*lst;

	if (!code)
	{
		lst = ptr;
		return (NULL);
	}
	if (ptr)
		lst_add_back(lst, ptr);
	return (lst);
}

int	p_length(int code)
{
	int			ret;
	static int	length;

	ret = length;
	if (code == 1)
		length++;
	else if (code == 2)
		length = 0;
	return (ret);
}

void	p_free(void)
{
	t_alloc_ptr	*lst;
	t_alloc_ptr	*tmp;

	lst = addr_save(NULL, 1);
	while (lst)
	{
		tmp = lst->next;
		free(lst->addr);
		free(lst);
		lst = tmp;
	}
	p_length(2);
}

void	*p_alloc(size_t sz)
{
	t_alloc_ptr	*lst;

	lst = new_node(sz);
	if (!lst)
		return (NULL);
	if (!p_length(1))
		addr_save(lst, 0);
	else
		addr_save(lst, 1);
	return (lst->addr);
}
