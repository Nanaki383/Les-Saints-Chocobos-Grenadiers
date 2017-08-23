/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:37:17 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 15:40:30 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int				ft_read_stdin(t_r *r)
{
	int		ret;
	char	buf[SIZE + 1];
	char	*buf_copy;
	int		verif;

	verif = 0;
	while ((ret = read(0, buf, SIZE)) != 0)
	{
		if (ret == -1)
			return (1);
		buf[ret] = '\0';
		if (verif == 0)
		{
			buf_copy = ft_strdup(buf);
			verif = 1;
		}
		else
			buf_copy = ft_strcadup(buf, buf_copy, ret);
	}
	if (!(ft_buf_is_printable(buf)))
		return (1);
	if ((ft_get_params(buf_copy, r) || ft_convert_to_tab(buf_copy, r) ||
				ft_check_map_empty(buf_copy, r)))
		return (1);
	return (0);
}

int				ft_read(int fd, t_r *r)
{
	int		ret;
	char	buf[SIZE + 1];
	char	*buf_copy;
	int		verif;

	verif = 0;
	while ((ret = read(fd, buf, SIZE)) != 0)
	{
		if (ret == -1)
			return (1);
		buf[ret] = '\0';
		if (verif == 0)
		{
			buf_copy = ft_strdup(buf);
			verif = 1;
		}
		else
			buf_copy = ft_strcadup(buf, buf_copy, ret);
	}
	if (!(ft_buf_is_printable(buf)))
		return (1);
	if ((ft_get_params(buf_copy, r) || ft_convert_to_tab(buf_copy, r) ||
				ft_check_map_empty(buf_copy, r)))
		return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	int		arg;
	int		fd;
	t_r		r;

	arg = 1;
	if (argc > 1)
	{
		while (arg < argc)
		{
			fd = open(argv[arg], O_RDONLY);
			if (ft_read(fd, &r))
				ft_error();
			close(fd);
			arg++;
		}
	}
	else if (argc == 1)
	{
		if (ft_read_stdin(&r))
			ft_error();
	}
	else
		return (1);
	return (0);
}
