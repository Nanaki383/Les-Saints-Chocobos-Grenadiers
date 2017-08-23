/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 09:32:37 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 22:32:59 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int		ft_check_map_obs(char *buf_copy, t_r *r)
{
	int i;

	i = r->paramline + 1;
	while (buf_copy[i])
	{
		if (buf_copy[i] != r->obs && buf_copy[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_map_empty(char *buf_copy, t_r *r)
{
	int i;

	i = 0;
	while (buf_copy[i] != '\n')
		i++;
	while ((buf_copy[i] == r->empty || buf_copy[i] == r->obs ||
					buf_copy[i] == '\n') && buf_copy[i])
	{
		if (ft_check_map_obs(buf_copy, r))
			return (1);
		if (buf_copy[i] == '\n' && buf_copy[i + 1] == '\n' && buf_copy)
			return (1);
		i++;
	}
	if (buf_copy[i] != '\0' && buf_copy[i - 1] != '\n')
		return (1);
	i = ft_strlen(buf_copy);
	if (buf_copy[i - 1] != '\n')
		return (1);
	return (0);
}
