/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:27:10 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 22:43:33 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int		ft_get_char(char *buf_copy, t_r *r, int i)
{
	if (buf_copy[i - 1] != buf_copy[i - 2]
			&& buf_copy[i - 1] != buf_copy[i - 3]
			&& buf_copy[i - 2] != buf_copy[i - 3])
	{
		r->full = buf_copy[i - 1];
		r->obs = buf_copy[i - 2];
		r->empty = buf_copy[i - 3];
		return (0);
	}
	else
	{
		return (1);
	}
	return (0);
}

int		ft_get_params(char *buf_copy, t_r *r)
{
	int		i;
	int		y;
	char	*nbline;

	i = 0;
	y = 0;
	while (buf_copy[i] != '\n')
		i++;
	r->paramline = i;
	nbline = (char *)malloc(sizeof(char) * (i - 3));
	if (!nbline)
		return (1);
	while (y < i - 3)
	{
		nbline[y] = buf_copy[y];
		y++;
	}
	nbline[y] = '\0';
	r->lenght = ft_get_number(nbline);
	if (r->lenght == 0)
		return (1);
	free(nbline);
	if (ft_get_char(buf_copy, r, i))
		return (1);
	return (0);
}
