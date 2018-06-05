/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilist_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:01:10 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 12:06:47 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

void		ft_ilist_delone(t_info *info)
{
	if (info)
	{
		if (info->owner)
			free(info->owner);
		if (info->group)
			free(info->group);
		if (info->time)
			free(info->time);
		if (info->name)
			free(info->name);
	}
}

void		ft_ilist_del(t_info **info)
{
	t_info	*temp;

	while (*info)
	{
		ft_ilist_delone(*info);
		temp = *info;
		*info = (*info)->next;
		free(temp);
	}
}
