/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_funcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:41:51 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/06 17:43:16 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

int		ft_flag_one(char *flags)
{
	flags[FLAG_LIST] = 0;
	flags[FLAG_ONE] = 1;
	return (0);
}

int		ft_flag_blocks(char *flags)
{
	flags[FLAG_BLKS] = 1;
	return (0);
}
