/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:32:54 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/07 14:55:24 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

t_addr		*ft_new_addr(t_info *addr)
{
	t_addr	*res;

	res = (t_addr*)malloc(sizeof(*res));
	res->addr = addr;
	res->next = 0;
	return (res);
}

void		ft_alist_pb(t_addr **begin, t_info *addr)
{
	while (*begin)
		begin = &((*begin)->next);
	*begin = ft_new_addr(addr);
}
