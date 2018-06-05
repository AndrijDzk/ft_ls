/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_places.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 12:29:55 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 16:34:48 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

static short	ft_set_mode(char *flags)
{
	short	res;

	if (flags[FLAG_LIST])
		res = 6010;
	else
		res = 1010;
	if (flags[FLAG_ALL])
		res += 10000;
	if (flags[FLAG_TIME])
		res += (flags[FLAG_REV] ? 400 : 300);
	else if (flags[FLAG_REV])
		res += 200;
	else
		res += 100;
	return (res);
}

static int		ft_print_missing(t_info *missing)
{
	while (missing)
	{
		ft_printf("%$ls: %s: No such file or directory\n", 2, missing->name);
		missing = missing->next;
	}
	return (0);
}

int				ft_rec_cond(char *name, char rec, char perm0)
{
	int		i;

	if (rec == 0)
		return (0);
	else if (perm0 != 'd')
		return (0);
	i = 0;
	while (name[i])
		i++;
	while (i > 0 && name[i - 1] != '/')
		i--;
	if (name[i] == '.' && (name[i + 1] == 0 || (name[i + 1] == '.' &&
		name[i + 2] == 0)))
		return (0);
	else
		return (1);
}

int				ft_print_dir(char *name, char *flags, short mode)
{
	t_info	*files;
	int		fields[FIELDS_AM];
	t_addr	*dirs;

	ft_bzero(fields, sizeof(int) * FIELDS_AM);
	files = ft_read_dir(name, fields, mode, flags);
	if (errno == EACCES)
		ft_printf("%$ls: %s: permission denied.\n", 2, name);
	if (((mode / 1000) % 10) != 2)
		ft_printf("\n%s:\n", name);
	else if (files)
		mode -= 2000;
	if (files && flags[FLAG_LIST])
		ft_printf("total %U\n", ft_count_blocks(files, flags));
	dirs = ft_print_files(files, fields, flags, 1);
	ft_proc_rec(dirs, flags, mode, name);
	return (0);
}

int				ft_proc_places(t_place *places, char *flags)
{
	t_info	*info[3];
	t_info	*temp;
	int		fields[FIELDS_AM];
	short	mode;

	ft_bzero(fields, sizeof(int) * FIELDS_AM);
	mode = ft_set_mode(flags);
	ft_fst_info(info, places, mode, fields);
	ft_print_missing(info[0]);
	ft_print_files(info[1], fields, flags, 0);
	mode = ((mode / 10000) * 10000) + (mode % 1000 - 10 + 1);
	temp = info[2];
	if (places->next == 0)
		mode += 2000;
	while (temp)
	{
		ft_print_dir(temp->name, flags, mode);
		temp = temp->next;
	}
	ft_ilist_del(info);
	ft_ilist_del(info + 1);
	ft_ilist_del(info + 2);
	return (0);
}
