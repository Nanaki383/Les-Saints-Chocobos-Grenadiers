/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:27:10 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 00:21:49 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

struct s_r		*ft_get_char(char *buf_copy,t_r *r,int i)
{
	if (buf_copy[i - 1] != buf_copy[i-2] && buf_copy[i - 1] != buf_copy[i - 3]
			&& buf_copy[i - 2] != buf_copy[i - 3])
	{
		r->full = buf_copy[i - 1];
		r->obs = buf_copy[i - 2];
		r->empty = buf_copy[i - 3];
		return (r);
	}
	else
	{
		ft_putstr("Need different arguments for empty, full, obs");
		return (0);
	}
	return (0);
}

struct s_r		*ft_get_params(char *buf_copy, t_r *r)
{
	int		i;
	int		y;
	char	*nbline;

	i = 0;
	y = 0;
	while (buf_copy[i] != '\n')
		i++;
	nbline =(char *)malloc(sizeof(char) * (i - 3));
	if (!nbline)
		return (NULL);
	while (y < i - 3)
	{
		nbline[y] = buf_copy[y];
		y++;
	}
	nbline[y] = '\0';
	r->lenght = ft_atoi(nbline);
	r = ft_get_char(buf_copy, r, i); 
	return (r);
}
