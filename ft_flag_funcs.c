/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:47:10 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/04 12:51:29 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

int		ft_flag_list(char *flags)
{
	flags[FLAG_ONE] = 0;
	flags[FLAG_LIST] = 1;
	return (1);
}

int		ft_flag_rec(char *flags)
{
	flags[FLAG_REC] = 1;
	return (1);
}

int		ft_flag_rev(char *flags)
{
	flags[FLAG_REV] = 1;
	return (1);
}

int		ft_flag_all(char *flags)
{
	flags[FLAG_ALL] = 1;
	return (1);
}

int		ft_flag_time(char *flags)
{
	flags[FLAG_TIME] = 1;
	return (1);
}
