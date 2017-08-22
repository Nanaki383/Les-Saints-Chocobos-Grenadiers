/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 22:58:11 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 00:34:13 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int			count_line(char *str, t_r *r)
{
	int		i;
	int		count;
	int		space;

	i = 0;
	count = 0;
	space = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		while (str[i++] != '\n' && str[i])
			space = 1;
		if (str[i] == '\n')
		{
			count += (space == 1) ? 1 : 0;
			space = 0;
			i++;
		}
	}
	if (r->lenght != count)
		return (-2);
	else
		return (count);
}

int			strlen_line(char *str, int i, t_r *r)
{
	int count;

	count = 0;
	while (str[i] != '\n' && str[i])
	{
		count++;
		i++;
	}
	if (r->width == 0)
	{
		r->width = count;
		ft_putnbr(r->width);
		return (count);	
	}
	else if (r->width != count)
	{
		//ft_putstr("map error");
		return (-1);
	}
	else
		return (count);
}

struct	s_r	*ft_convert_to_tab(char *str, t_r *r)
{
	int		i;
	int		y;
	int		z;

	r->width = 0;
	z = 0;
	i = 0;
	if ((r->map = malloc(sizeof(char) * (count_line(str, r) + 2))) == 0)
		return (NULL);
	while (str[i] != 0)
	{
		while (str[i] == '\n')
			i++;
		if (str[i] != '\0')
		{
			y = 0;
			if (!(r->map[z] = malloc(sizeof(char) * strlen_line(str, i , r) + 1)))
				return (NULL);
			while (str[i] != '\n' && str[i])
				r->map[z][y++] = str[i++];
			r->map[z++][y] = '\0';
		}
	}
	r->map[z] = 0;
	return (r);
}
