/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 13:58:51 by acalleja          #+#    #+#             */
/*   Updated: 2017/08/15 22:52:34 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int a;
	int negative;

	i = 0;
	negative = 0;
	a = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		i++;
		negative = 1;
	}
	if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		a = a * 10 + ((int)str[i] - 48);
		i++;
	}
	if (negative == 1)
		a = -a;
	return (a);
}
