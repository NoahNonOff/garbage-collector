/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <nbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:32:18 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/07/30 18:37:29 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef P_ALLOC_H
# define P_ALLOC_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_alloc_ptr {
	void				*addr;
	struct s_alloc_ptr	*next;
}	t_alloc_ptr;

/* ========= list =========== */
t_alloc_ptr	*new_node(size_t sz);
void		lst_add_back(t_alloc_ptr *lst, t_alloc_ptr *new);

/* ========================== */
void		*p_alloc(size_t sz);
void		p_free(void);

#endif
