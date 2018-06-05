/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:29:19 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 15:52:04 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

int		ft_flag_funcs_arr_init(t_flag *funcs)
{
	funcs[FLAG_ONE] = &ft_flag_one;
	funcs[FLAG_LIST] = &ft_flag_list;
	funcs[FLAG_REC] = &ft_flag_rec;
	funcs[FLAG_REV] = &ft_flag_rev;
	funcs[FLAG_ALL] = &ft_flag_all;
	funcs[FLAG_TIME] = &ft_flag_time;
	funcs[FLAG_BLKS] = &ft_flag_blocks;
	return (1);
}

int		ft_scan_flag(char f, char *flags)
{
	char	*fgs;
	t_flag	funcs[FLAGS_AM];
	int		i;

	fgs = "1lRrats";
	ft_flag_funcs_arr_init(funcs);
	i = ft_find_char(fgs, f);
	if (i >= 0)
		funcs[i](flags);
	else
		return (1);
	return (0);
}

int		ft_scan_flags(char *str, char *flags)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (ft_scan_flag(str[i], flags))
		{
			ft_printf("ft_ls: illegal option -- %c\n", str[i]);
			ft_printf("usage: ft_ls [rlRats1] [file ...]\n");
			return (1);
		}
		else
			i++;
	}
	return (0);
}
