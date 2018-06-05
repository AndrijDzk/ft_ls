/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 09:52:14 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 16:47:25 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"
#include <fcntl.h>
#include <unistd.h>

int				ft_proc_rec(t_addr *dirs, char *flags, short mode, char *name)
{
	t_addr	*temp;
	char	*subdir;

	while (dirs)
	{
		temp = dirs->next;
		subdir = ft_get_path(name, ((dirs->addr)->name), 10001);
		ft_ilist_delone(dirs->addr);
		free(dirs->addr);
		ft_print_dir(subdir, flags, mode);
		free(subdir);
		free(dirs);
		dirs = temp;
	}
	return (0);
}

static void		ft_print_long_format(t_info *begin, int *fields)
{
	ft_printf("%s ", begin->perm);
	ft_printf("%*u ", fields[0], begin->links);
	ft_printf("%-*s  ", fields[1], begin->owner);
	ft_printf("%-*s  ", fields[2], begin->group);
	if ((begin->perm)[0] == 'c' || (begin->perm)[0] == 'b')
		ft_printf("%3lld, %3lld ", major(begin->devid),
			minor(begin->devid));
	else
		ft_printf("%*lld ", fields[3], begin->size);
	ft_printf("%-*s ", fields[4], begin->time);
}

static void		ft_next(t_info **begin, char *flags, char mode, t_addr **res)
{
	int		b;
	t_info	*temp;

	b = ft_rec_cond((*begin)->name, flags[FLAG_REC], ((*begin)->perm)[0]);
	if (b)
		ft_alist_pb(res, *begin);
	if ((mode % 10) == 1 && b == 0)
	{
		temp = (*begin)->next;
		ft_ilist_delone(*begin);
		free(*begin);
		*begin = temp;
	}
	else
		*begin = (*begin)->next;
}

t_addr			*ft_print_files(t_info *begin, int *fields, char *flg, char md)
{
	t_addr	*res;
	t_info	*temp;
	int		b;

	res = 0;
	while (begin)
	{
		if (flg[FLAG_BLKS])
			ft_printf("%*lld ", fields[6], begin->blocks);
		if (flg[FLAG_LIST])
			ft_print_long_format(begin, fields);
		ft_printf("%s", begin->name);
		if ((begin->target)[0] && flg[FLAG_LIST])
			ft_printf(" -> %s", begin->target);
		ft_printf("\n");
		ft_next(&begin, flg, md, &res);
	}
	return (res);
}

int				main(int argc, char **argv)
{
	t_place		*places;
	char		flags[FLAGS_AM];
	int			fields[FIELDS_AM];
	int			ret[1];

	ft_bzero(fields, sizeof(int) * FIELDS_AM);
	ft_bzero(flags, sizeof(char) * FLAGS_AM);
	places = 0;
	if ((ret[0] = ft_scan(argc, argv, &places, flags)) < 0)
		return (1);
	else
	{
		ft_proc_places(places, flags);
	}
	ft_plist_clear(&places);
	return (0);
}
