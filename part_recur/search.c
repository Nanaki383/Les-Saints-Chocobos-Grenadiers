/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 03:04:58 by glegendr          #+#    #+#             */
/*   Updated: 2017/08/23 15:21:55 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	search(char **tab, char empty, char obst, char sqr)
{
	struct s_set_point s;

	s.obst = obst;
	s.empty = empty;
	s.square = sqr;
	s.i = 0;
	s.j = 0;
	s.lmax = 6;
	s.smax = 0;
	s.imax = 5;
	s.size = 0;
	s.cmax = 0;
	s.border = 3;
	int r;
	r = 0;
	check(tab, s);
}

int		main(int argc, char **argv)
{
	argc = 0;
	char empty;
	char obst;
	char sqr;

	empty = '.';
	obst = 'o';
	sqr = 'X';
	search(&argv[1], empty, obst, sqr);
}
