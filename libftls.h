/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 12:44:15 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 16:59:41 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTLS_H
# define LIBFTLS_H
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <dirent.h>
# include "libscan.h"
# include "libplist.h"
# include "libalist.h"
# include "libinfo.h"
# include "cstdlib/cstdlib.h"
# define FIELDS_AM 9

int				ft_scan(int argc, char **argv, t_place **begin, char *flags);

t_info			*ft_read_dir(char *path, int *fields, short mode, char *flags);

int				ft_fst_info(t_info **inf, t_place *plcs, short mode, int *fds);

t_addr			*ft_print_files(t_info *begin, int *fields, char *fgs, char md);

int				ft_proc_places(t_place *places, char *flags);

unsigned long	ft_count_blocks(t_info *info, char *flags);

int				ft_rec_cond(char *name, char rec, char perm0);

int				ft_proc_rec(t_addr *dirs, char *flags, short mode, char *name);

int				ft_print_dir(char *name, char *flags, short mode);

#endif
