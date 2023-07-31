/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <nbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:34:34 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/07/31 15:00:44 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "p_alloc.h"

/*------------- proto ---------------*/
t_alloc_ptr	*new_node(size_t sz);
t_alloc_ptr	*remove_address(int index, t_alloc_ptr *lst);
void		lst_add_back(t_alloc_ptr *lst, t_alloc_ptr *new);

/* ================================= */

// addr_save(NULL, 1) -> return list's address
// addr_save(addr, 0) -> create the list
// addr_save(addr, 1) -> add to the end of list

t_alloc_ptr	*addr_save(t_alloc_ptr *ptr, int code)
{
	static t_alloc_ptr	*lst;

	if (!code)
		lst = ptr;
	else if (ptr)
		lst_add_back(lst, ptr);
	return (lst);
}

// p_length(1) -> length++;
// p_length(0) -> length = 0;

int	p_length(int code)
{
	int			ret;
	static int	length;

	ret = length;
	if (code == 1)
		length++;
	else if (code == 2)
		length = 0;
	else if (code == 3)
		length--;
	return (ret);
}

void	p_free_all(void)
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

void	p_free(void *addr)
{
	int			index;
	t_alloc_ptr	*lst;

	index = 0;
	lst = addr_save(NULL, 1);
	while (lst)
	{
		if (lst->addr == addr)
			break ;
		lst = lst->next;
		index++;
	}
	if (!lst)
		return ;
	lst = remove_address(index, addr_save(NULL, 1));
	addr_save(lst, 0);
	p_length(3);
}

void	*p_alloc(size_t sz)
{
	t_alloc_ptr	*lst;

	lst = new_node(sz);
	if (!lst)
		return (NULL);
	if (p_length(1) == 0)
		addr_save(lst, 0);
	else
		addr_save(lst, 1);
	return (lst->addr);
}
