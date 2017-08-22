/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:53:21 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 00:44:52 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# define SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_r
{
	int		width;
	int		lenght;
	char	empty;
	char	obs;
	char	full;
	char	**map;
}					t_r;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int n);
char				*ft_strcadup(char *buf, char *buf_copy);
char				*ft_strdup(char *src);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
struct	s_r			*ft_convert_to_tab(char *str, t_r *r);
struct	s_r			*ft_get_params(char *buf_copy, t_r *r);

#endif
