/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 09:49:11 by glegendr          #+#    #+#             */
/*   Updated: 2017/08/23 21:39:11 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include "read.h"

typedef	struct	s_set_point
{
	int		x;
	int		y;
	int		cmax;
	int		border;
	int		lmax;
	int		imax;
	int		smax;
	char	obst;
	char	empty;
	char	square;
	int		i;
	int		j;
	int		size;
	char	**tab;
}				t_set_point;

void			search(t_r *r);
int				check(struct s_set_point s);
int				checkcol(struct s_set_point s);
int				checkline(struct s_set_point s);
int				affichage(struct s_set_point s);
#endif
