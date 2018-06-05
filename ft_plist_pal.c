/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plist_pal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:09:42 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 12:09:44 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

t_place		*ft_new_place(char *name)
{
	t_place		*res;
	int			i;

	res = (t_place*)malloc(sizeof(*res));
	res->name = 0;
	if (name)
	{
		res->name = (char*)malloc(sizeof(*res) * (ft_strlen(name) + 1));
		i = -1;
		while (name[++i])
			(res->name)[i] = name[i];
		(res->name)[i] = 0;
	}
	res->path = 0;
	return (res);
}

void		ft_plist_pal(t_place **begin, char *name)
{
	t_place		*temp;

	while (*begin && ft_strdiff((*begin)->name, name) < 0)
		begin = &((*begin)->next);
	temp = *begin;
	*begin = ft_new_place(name);
	(*begin)->next = temp;
}

void		ft_plist_clear(t_place **begin)
{
	t_place		*temp;

	while (*begin)
	{
		if ((*begin)->name)
			free((*begin)->name);
		if ((*begin)->path)
			free((*begin)->path);
		temp = (*begin)->next;
		free(*begin);
		*begin = temp;
	}
}
