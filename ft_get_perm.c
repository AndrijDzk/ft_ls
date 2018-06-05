/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_perm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:01:52 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 11:54:39 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

static char	ft_get_type(mode_t mode)
{
	if ((mode & S_IFSOCK) == S_IFSOCK)
		return ('s');
	else if ((mode & S_IFLNK) == S_IFLNK)
		return ('l');
	else if ((mode & S_IFREG) == S_IFREG)
		return ('-');
	else if ((mode & S_IFBLK) == S_IFBLK)
		return ('b');
	else if ((mode & S_IFDIR) == S_IFDIR)
		return ('d');
	else if ((mode & S_IFCHR) == S_IFCHR)
		return ('c');
	else if ((mode & S_IFIFO) == S_IFIFO)
		return ('p');
	else
		return ('-');
}

static char	ft_get_third(mode_t mode, int i)
{
	if (((i - 1) / 3) < 2)
	{
		if ((!(mode & S_IXUSR) && (mode & S_ISUID) == S_ISUID && !((i - 1) / 3))
			||
			(!(mode & S_IXGRP) && (mode & S_ISGID) == S_ISGID && ((i - 1) / 3)))
			return ('S');
		else if (((mode & S_IXUSR) == S_IXUSR &&
				(mode & S_ISUID) == S_ISUID && !((i - 1) / 3)) ||
				((mode & S_IXGRP) == S_IXGRP &&
				(mode & S_ISGID) == S_ISGID && ((i - 1) / 3) == 1))
			return ('s');
	}
	else if (((i - 1) / 3) == 2 && (mode & S_ISVTX) == S_ISVTX)
	{
		if ((mode & S_IXOTH) == 0)
			return ('T');
		else
			return ('t');
	}
	if (((mode & S_IXUSR) == S_IXUSR && ((i - 1) / 3) == 0) ||
		((mode & S_IXGRP) == S_IXGRP && ((i - 1) / 3) == 1) ||
		((mode & S_IXOTH) == S_IXOTH && ((i - 1) / 3) == 2))
		return ('x');
	else
		return ('-');
}

static char	ft_get_ex(char *name)
{
	acl_t	temp;

	if (listxattr(name, 0, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	temp = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	if (temp)
	{
		acl_free(temp);
		return ('+');
	}
	else
		return (' ');
}

void		ft_get_perm(char *perm, struct stat *info, char *name)
{
	int				i;
	unsigned short	mask;

	perm[0] = ft_get_type(info->st_mode);
	mask = 256;
	i = 1;
	while (mask > 0)
	{
		if ((info->st_mode) & mask)
		{
			if (((i + 1) % 3) == 0)
				perm[i] = 'w';
			else if (((i + 2) % 3) == 0)
				perm[i] = 'r';
			else
				perm[i] = ft_get_third(info->st_mode, i);
		}
		else
			perm[i] = '-';
		mask /= 2;
		i++;
	}
	perm[10] = ft_get_ex(name);
	perm[11] = 0;
}
