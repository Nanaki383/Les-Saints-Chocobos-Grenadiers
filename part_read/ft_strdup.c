/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:16:30 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 15:25:13 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

char*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	len = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(*src) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
