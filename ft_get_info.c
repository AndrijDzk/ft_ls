/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:31:47 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 16:48:58 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"

static char	*ft_get_time(time_t ltime)
{
	char	*res;
	char	*temp;
	char	*temp2;
	char	*temp3;
	time_t	curr;

	temp = ctime(&ltime);
	if ((time(&curr) - ltime) >= 15811200)
	{
		temp2 = ft_strsub(temp, 4, 7);
		temp3 = ft_strsub(temp, 19, 5);
		res = ft_strjoin(temp2, temp3);
		free(temp2);
		free(temp3);
	}
	else
		res = ft_strsub(temp, 4, 12);
	return (res);
}

static int	ft_name_check(char *path)
{
	int		i;

	i = 0;
	while (path[i])
		i++;
	while (i > 0 && path[i - 1] != '/')
		i--;
	if (path[i] == '.')
		return (0);
	else
		return (1);
}

char		*ft_get_path(char *path, char *name, short mode)
{
	char	*res;
	int		i;
	int		j;

	if ((mode % 10))
	{
		i = ft_strlen(path);
		j = i;
		if (j)
			j += ((path[i - 1] == '/') ? 0 : 1);
		res = (char*)malloc(sizeof(*res) * (j + ft_strlen(name) + 1));
		ft_strcpy(res, path);
		if (path[0] && path[i - 1] != '/')
			ft_strcpy(res + i++, "/");
		ft_strcpy(res + i, name);
	}
	else
		res = ft_strdup(name);
	if (ft_name_check(res) == 0 && (((mode / 10000) % 10) != 1 &&
		((mode / 1000) % 10) != 1 && ((mode / 1000) % 10) != 6))
	{
		free(res);
		return (0);
	}
	return (res);
}

static int	ft_copy_info(t_info *res, struct stat *buf, char *path, short mode)
{
	void		*temp;

	ft_get_perm(res->perm, buf, path);
	res->links = buf->st_nlink;
	temp = getpwuid(buf->st_uid);
	res->owner = ft_strdup(((struct passwd*)temp)->pw_name);
	temp = getgrgid(buf->st_gid);
	res->group = ft_strdup(((struct group*)temp)->gr_name);
	res->devid = buf->st_rdev;
	res->size = buf->st_size;
	res->time = ft_get_time((buf->st_mtimespec).tv_sec);
	res->time2 = (buf->st_mtimespec).tv_sec;
	res->time3 = (buf->st_mtimespec).tv_nsec;
	res->blocks = buf->st_blocks;
	if ((res->perm)[0] == 'l')
		(res->target)[readlink(path, res->target, MAXNAMLEN)] = 0;
	return (0);
}

t_info		*ft_get_info(char *path, char *name, short mode)
{
	t_info		*res;
	struct stat	buf;

	if ((path = ft_get_path(path, name, mode)) == 0)
		return (0);
	res = (t_info*)malloc(sizeof(*res));
	(res->perm)[0] = 0;
	(res->target)[0] = 0;
	res->owner = 0;
	res->group = 0;
	res->time = 0;
	res->name = path;
	res->next = 0;
	if (lstat(path, &buf))
		return (res);
	ft_copy_info(res, &buf, path, mode);
	if (((mode / 10) % 10) == 0)
	{
		free(path);
		res->name = ft_strdup(name);
	}
	return (res);
}
