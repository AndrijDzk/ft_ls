/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libscan.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:34:03 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 10:55:59 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSCAN_H
# define LIBSCAN_H
# define FLAGS_AM 9
# define FLAG_ONE 0
# define FLAG_LIST 1
# define FLAG_REC 2
# define FLAG_REV 3
# define FLAG_ALL 4
# define FLAG_TIME 5
# define FLAG_BLKS 6
# define FLAG_TOTAL 7

int				ft_scan_flags(char *str, char *flags);

typedef int		(*t_flag)(char *flags);

int				ft_flag_one(char *flags);

int				ft_flag_list(char *flags);

int				ft_flag_rec(char *flags);

int				ft_flag_rev(char *flags);

int				ft_flag_all(char *flags);

int				ft_flag_time(char *flags);

int				ft_flag_blocks(char *flags);

#endif
