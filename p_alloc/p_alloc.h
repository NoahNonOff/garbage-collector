/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <nbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:32:18 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/07/31 14:03:59 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef P_ALLOC_H
# define P_ALLOC_H

# include <stdlib.h>
# include <stdio.h>

// # define malloc(X) p_alloc(X) //

/* =========== utils =========== */
typedef struct s_alloc_ptr {
	void				*addr;
	size_t				size;
	struct s_alloc_ptr	*next;
}	t_alloc_ptr;

/* =========== protos ========== */
void		*p_alloc(size_t sz);
void		p_free(void *addr);
void		p_free_all(void);

#endif
