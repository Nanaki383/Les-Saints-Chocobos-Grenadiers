/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:14:30 by glegendr          #+#    #+#             */
/*   Updated: 2017/08/23 21:26:18 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		affichage(struct s_set_point s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s.tab[i])
	{
		while (s.tab[i][j] != '\0')
		{
			if (s.x <= i && i <= (s.x + s.smax - 1)
					&& s.y <= j && j <= (s.y + s.smax - 1))
			{
				s.tab[i][j] = s.square;
			}
			write(1, &s.tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (1);
}
