/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:58:34 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 22:56:35 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void		ft_free_tab(t_r *r)
{
	int i;

	i = 0;
	if (r->map != NULL)
	{
		while (r->lenght > i)
		{
			free(r->map[i]);
			i++;
		}
		free(r->map);
		r->map = NULL;
	}
	r->width = 0;
	r->lenght = 0;
	r->paramline = 0;
}
