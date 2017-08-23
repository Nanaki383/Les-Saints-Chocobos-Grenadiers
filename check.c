/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:12:53 by glegendr          #+#    #+#             */
/*   Updated: 2017/08/23 21:24:52 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		checkline(struct s_set_point s)
{
	int compt;
	int i;

	i = s.i;
	compt = 0;
	if (s.tab[s.j + s.size] == 0)
		return (0);
	while (compt <= s.size)
	{
		if (s.tab[s.j + s.size][i] == s.obst)
			return (0);
		i++;
		compt++;
	}
	return (1);
}

int		checkcol(struct s_set_point s)
{
	int		compt;
	int		j;

	j = s.j;
	compt = 0;
	if (s.tab[s.j][s.i + s.size] == 0)
		return (0);
	while (compt <= s.size)
	{
		if (s.tab[j][s.i + s.size] == s.obst)
			return (0);
		j++;
		compt++;
	}
	return (1);
}

int		ft_verif(struct s_set_point s)
{
	if (s.i == s.imax && s.j < s.lmax)
	{
		s.i = 0;
		s.j += 1;
		s.size = 0;
		if (s.j < s.lmax)
			check(s);
		return (0);
	}
	if (s.j < s.lmax)
	{
		s.i += 1;
		s.size = 0;
		check(s);
	}
	return (0);
}

int		check(struct s_set_point s)
{
	if (s.i == s.imax && s.j == s.lmax - 1)
		affichage(s);
	if (checkline(s) == 1 && checkcol(s) == 1)
	{
		s.size += 1;
		check(s);
	}
	else
	{
		if (s.size > s.smax)
		{
			s.smax = s.size;
			s.x = s.j;
			s.y = s.i;
		}
		ft_verif(s);
	}
	return (0);
}
