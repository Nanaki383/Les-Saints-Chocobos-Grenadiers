/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:12:53 by glegendr          #+#    #+#             */
/*   Updated: 2017/08/23 14:46:18 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		checkline(char **tab, struct s_set_point s)
{
	int compt;
	int i;

	i = s.i;
	compt = 0;
	if (tab[s.j + s.size] == 0)
		return (0);
	while (compt <= s.size)
	{
		if (tab[s.j + s.size][i] == s.obst)
			return (0);
		i++;
		compt++;
	}
	return (1);
}

int		checkcol(char **tab, struct s_set_point s)
{
	int		compt;
	int		j;

	j = s.j;
	compt = 0;
	if (tab[s.j][s.i + s.size] == 0)
		return (0);
	while (compt <= s.size)
	{
		if (tab[j][s.i + s.size] == s.obst)
			return (0);
		j++;
		compt++;
	}
	return (1);
}

int		ft_verif(char **tab, struct s_set_point s)
{
	if (s.i == s.imax && s.j < s.lmax)
	{
		s.i = 0;
		s.j += 1;
		s.size = 0;
		if (s.j < s.lmax)
			check(tab, s);
		return (0);
	}
	if (s.j < s.lmax)
	{
		s.i += 1;
		s.size = 0;
		check(tab, s);
	}
	return (0);
}

int		check(char **tab, struct s_set_point s)
{
	if (s.i == s.imax && s.j == s.lmax - 1)
		affichage(tab, s);
	if (checkline(tab, s) == 1 && checkcol(tab, s) == 1)
	{
		s.size += 1;
		check(tab, s);
	}
	else
	{
		if (s.size > s.smax)
		{
			s.smax = s.size;
			s.x = s.j;
			s.y = s.i;
		}
		ft_verif(tab, s);
	}
	return (0);
}
