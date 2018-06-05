/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:48:50 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 12:38:53 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

unsigned long	ft_count_blocks(t_info *info, char *flags)
{
	unsigned long	res;

	res = 0;
	while (info)
	{
		if (flags[FLAG_ALL] || (info->name)[0] != '.')
			res += info->blocks;
		info = info->next;
	}
	return (res);
}

static void		ft_get_sizes(t_info *file, int *sizes)
{
	sizes[0] = ft_count_digits(file->links, 10);
	sizes[1] = ft_strlen(file->owner);
	sizes[2] = ft_strlen(file->group);
	if ((file->perm)[0] == 'c' || (file->perm)[0] == 'b')
	{
		sizes[7] = ft_count_digits(major(file->devid), 10);
		sizes[8] = ft_count_digits(minor(file->devid), 10);
		sizes[3] = 8;
	}
	else
	{
		sizes[7] = 0;
		sizes[8] = 0;
		sizes[3] = ft_count_digits(file->size, 10);
	}
	sizes[4] = ft_strlen(file->time);
	sizes[5] = ft_strlen(file->name);
	sizes[6] = ft_count_digits(file->blocks, 10);
}

static int		ft_size_cmp(t_info *file, int *fields, char flag_all)
{
	int		sizes[FIELDS_AM];
	int		i;

	if (flag_all == 0 && (file->name)[0] == '.')
		return (0);
	ft_get_sizes(file, sizes);
	i = 0;
	while (i < FIELDS_AM)
	{
		if (sizes[i] > fields[i])
			fields[i] = sizes[i];
		i++;
	}
	return (1);
}

t_info			*ft_read_dir(char *path, int *fields, short mode, char *flags)
{
	DIR				*dir;
	struct dirent	*entry;
	t_info			*res;
	t_info			*temp;
	char			b;

	b = 0;
	res = 0;
	errno = 0;
	dir = opendir(path);
	if (dir)
	{
		while ((entry = readdir(dir)))
		{
			temp = ft_ilist_push(&res, path, entry->d_name, mode);
			if (temp)
			{
				ft_size_cmp(temp, fields, flags[FLAG_ALL]);
			}
		}
		closedir(dir);
	}
	return (res);
}

int				ft_fst_info(t_info **inf, t_place *plcs, short mode, int *flds)
{
	int		i;
	t_info	*temp;

	inf[0] = 0;
	inf[1] = 0;
	inf[2] = 0;
	while (plcs)
	{
		temp = ft_ilist_push(inf, "", plcs->name, mode);
		if (temp)
			ft_size_cmp(temp, flds, (mode / 10000) % 10000);
		plcs = plcs->next;
	}
	return (0);
}
