/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 03:04:58 by glegendr          #+#    #+#             */
/*   Updated: 2017/08/23 21:39:13 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "read.h"

void	search(t_r *r)
{
	t_set_point s;

	s.obst = r->obs;
	s.empty = r->empty;
	s.square = r->full;
	s.i = 0;
	s.j = 0;
	s.lmax = r->lenght;
	s.smax = 0;
	s.imax = r->width;
	s.size = 0;
	s.tab = r->map;
	check(s);
}
