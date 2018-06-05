/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libplist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 09:14:53 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 12:40:38 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPLIST_H
# define LIBPLIST_H

typedef struct	s_place
{
	char			*path;
	char			*name;
	struct s_place	*next;
}				t_place;

t_place			*ft_new_place(char *name);

void			ft_plist_pal(t_place **begin, char *name);

void			ft_plist_clear(t_place **begin);

#endif
