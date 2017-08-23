/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 09:49:11 by glegendr          #+#    #+#             */
/*   Updated: 2017/08/23 14:50:27 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <stdlib.h>
# include <unistd.h>

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
char			**affichagei(char **tab, t_set_point s);
int				check(char **tab, struct s_set_point s);
int				checkcol(char **tab, struct s_set_point s);
int				checkline(char **tab, struct s_set_point s);
int				affichage(char **tab, struct s_set_point s);
#endif
