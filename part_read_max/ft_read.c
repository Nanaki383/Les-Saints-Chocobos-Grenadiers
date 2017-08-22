/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:06:51 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 00:59:23 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

struct	s_r		*ft_read(int fd, t_r *r)
{
	int		ret;
	char	buf[SIZE + 1];
	char	*buf_copy;
	int		verif;

	verif = 0;
	while ((ret = read(fd, buf, SIZE)) != 0)
	{
		if (ret == -1)
		{
			ft_putstr("map error\n");
			return (NULL);
		}
		buf[ret] = '\0';
		if (verif == 0)
		{
			buf_copy = ft_strdup(buf);
			verif = 1;
		}
		else
			buf_copy = ft_strcadup(buf, buf_copy);
	}
	ft_putstr(buf_copy);
	ft_get_params(buf_copy, r);
	ft_convert_to_tab(buf_copy, r);
	return (r);
}

int				main(int argc, char **argv)
{
	int		arg;
	int		fd;
	t_r		r;

	arg = 1;
	if (argc > 1)
	{
		while(arg < argc)
		{
			if ((fd = open(argv[arg], O_RDWR)) == -1)
			{
				ft_putstr("map error\n");
			}
			ft_read(fd, &r);
			close(fd);
			arg++;
		}
	}
	//else if (argc == 1)
	//	ft_read_stdin();
	return (0);
}
