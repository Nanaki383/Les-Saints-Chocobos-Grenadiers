/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:13:53 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 15:32:30 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

char	*ft_strcadup(char *buf, char *buf_copy, int ret)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	copy = ft_strdup(buf_copy);
	free(buf_copy);
	if (!(buf_copy = (char *)malloc(sizeof(char) * ft_strlen(copy) + ret + 1)))
		return (NULL);
	while (copy[i])
	{
		buf_copy[i] = copy[i];
		i++;
	}
	while (buf[j])
	{
		buf_copy[i] = buf[j];
		i++;
		j++;
	}
	buf_copy[i] = '\0';
	free(copy);
	return (buf_copy);
}
