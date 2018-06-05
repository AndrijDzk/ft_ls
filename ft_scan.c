/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:28:27 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 16:47:05 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

int		ft_scan(int argc, char **argv, t_place **begin, char *flags)
{
	int		i;
	int		ret;

	ret = 0;
	if (argc < 2)
		ft_plist_pal(begin, ".");
	else
	{
		i = 1;
		while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
		{
			if (ft_strdiff(argv[i++], "--") == 0)
				break ;
			else if (ft_scan_flags(argv[i - 1], flags))
				return (-1);
		}
		if (i == argc)
			ft_plist_pal(begin, ".");
		while (i < argc)
		{
			ft_plist_pal(begin, argv[i++]);
			ret++;
		}
	}
	return (ret);
}
