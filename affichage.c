/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfavier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:04:52 by kfavier           #+#    #+#             */
/*   Updated: 2017/08/22 15:01:49 by kfavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	affichage(char **tab, struct s_set_point s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i][j])
	{
		while (tab[i][j] != '\0')
		{
			if (s.x <= i && i <= (s.x + s.size - 1)
					&& s.y <= j && j <= (s.y + s.size - 1))
			{
				tab[i][j] = s.square;
			}
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
