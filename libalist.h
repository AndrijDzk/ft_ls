/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libalist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:33:09 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/07 15:02:57 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBALIST_H
# define LIBALIST_H
# include "libinfo.h"

typedef struct	s_addr
{
	t_info			*addr;
	struct s_addr	*next;
}				t_addr;

t_addr			*ft_new_addr(t_info *addr);

void			ft_alist_pb(t_addr **begin, t_info *addr);

#endif
