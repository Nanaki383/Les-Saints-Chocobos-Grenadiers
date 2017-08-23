/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:37:17 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 21:31:32 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "read.h"

int				ft_read_stdin(t_r *r)
{
	int		ret;
	char	buf[SIZE + 1];
	char	*buf_copy;
	int		verif;

	verif = 0;
	buf_copy = NULL; 
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
	if (buf_copy == NULL)
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
	buf_copy = NULL;
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
	if ( buf_copy == NULL)
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

	arg = 0;
	if (argc > 1)
		while (++arg < argc)
		{
			fd = open(argv[arg], O_RDONLY);
			if (fd < 0  || ft_read(fd, &r))
				ft_error();
			search(&r);
			close(fd);
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
