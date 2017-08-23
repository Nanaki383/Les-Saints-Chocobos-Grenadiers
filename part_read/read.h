/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:53:21 by mlauer            #+#    #+#             */
/*   Updated: 2017/08/23 16:22:57 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# define SIZE 819
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_r
{
	int		paramline;
	int		width;
	int		lenght;
	char	empty;
	char	obs;
	char	full;
	char	**map;
}					t_r;

void				ft_putchar(char c);
void				ft_error(void);
void				ft_putnbr(int n);
void				ft_putstr(char *str);
char				*ft_strcadup(char *buf, char *buf_copy, int ret);
char				*ft_strdup(char *src);
int					ft_get_number(char *str);
int					ft_strlen(char *str);
int					ft_convert_to_tab(char *str, t_r *r);
int					ft_get_params(char *buf_copy, t_r *r);
int					ft_check_map_empty(char *buf_copy, t_r *r);
int					ft_buf_is_printable(char *buf);

#endif
