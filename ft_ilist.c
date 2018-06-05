/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:12:09 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 16:45:30 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

static int	ft_while(t_info *begin, t_place *place, t_info *temp, short mode)
{
	if (begin == 0)
		return (0);
	else if (((mode / 100) % 10) == 1 ||
			(((mode / 100) % 10) == 3 &&
			temp->time2 == begin->time2 && temp->time3 == begin->time3))
		return (ft_strdiff(begin->name, place->name) < 0);
	else if (((mode / 100) % 10) == 2 ||
			(((mode / 100) % 10) == 4 &&
			temp->time2 == begin->time2 && temp->time3 == begin->time3))
		return (ft_strdiff(begin->name, place->name) > 0);
	else if (((mode / 100) % 10) == 3)
	{
		if (temp->time2 != begin->time2)
			return (temp->time2 < begin->time2);
		else
			return (temp->time3 < begin->time3);
	}
	else if (((mode / 100) % 10) == 4)
	{
		if (temp->time2 != begin->time2)
			return (temp->time2 > begin->time2);
		else
			return (temp->time3 > begin->time3);
	}
	return (0);
}

static int	ft_cut_name(char *name)
{
	int		i;

	i = 0;
	while (name[i])
		i++;
	if (name[i - 1] == '/' && i > 1)
	{
		i--;
		name[i] = 0;
	}
	while (i > 0 && name[i - 1] != '/')
	{
		i--;
		name[i] = 0;
	}
	return (0);
}

static int	ft_follow_link(char *name, t_info **temp, short mode)
{
	t_info *temp2;

	ft_cut_name(name);
	temp2 = ft_get_info(name, (*temp)->target, mode + 1);
	free(*temp);
	*temp = temp2;
	return (0);
}

static int	ft_select_list(t_info ***begin, t_info *temp, short *mode)
{
	if ((temp->perm)[0] == 'd')
		*begin = *begin + 2;
	else if ((temp->perm)[0] != 0)
		*begin = *begin + 1;
	else
		*mode = 1100;
	return (0);
}

t_info		*ft_ilist_push(t_info **begin, char *path, char *name, short mode)
{
	t_info		*temp;
	t_info		*temp2;
	t_place		place;

	place.path = path;
	place.name = name;
	temp = ft_get_info(path, name, mode);
	if (temp == 0)
		return (0);
	if ((temp->perm)[0] == 'l' && ((mode / 1000) % 10) == 1)
		ft_follow_link(name, &temp, mode);
	if (((mode / 1000) % 5) == 1)
		ft_select_list(&begin, temp, &mode);
	while (ft_while(*begin, &place, temp, mode))
		begin = &((*begin)->next);
	temp2 = *begin;
	*begin = temp;
	(*begin)->next = temp2;
	if ((((mode / 1000) % 10) != 1 && ((mode / 1000) % 10) != 6)
		|| (((*begin)->perm)[0] && ((*begin)->perm)[0] != 'd'))
		return (*begin);
	else
		return (0);
}
