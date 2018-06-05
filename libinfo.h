/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libinfo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:40:17 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 14:54:36 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBINFO_H
# define LIBINFO_H
# include <sys/dir.h>

typedef struct	s_info
{
	char			perm[12];
	nlink_t			links;
	char			*owner;
	char			*group;
	dev_t			devid;
	off_t			size;
	char			*time;
	time_t			time2;
	long			time3;
	blkcnt_t		blocks;
	char			*name;
	char			target[MAXNAMLEN];
	struct s_info	*next;
}				t_info;

char			*ft_get_path(char *path, char *name, short mode);

void			ft_get_perm(char *perm, struct stat *info, char *name);

t_info			*ft_get_info(char *path, char *name, short mode);

t_info			*ft_ilist_push(t_info **begin, char *path, char *nm, short md);

void			ft_ilist_delone(t_info *info);

void			ft_ilist_del(t_info **info);

#endif
