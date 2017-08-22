/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfavier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:10:58 by kfavier           #+#    #+#             */
/*   Updated: 2017/08/22 14:11:31 by kfavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=fndef FT_HEADER_H
# define FT_HEADER_H
#include <stdlib.h>

typedef    struct    s_set_point
{
	char **coormax;
	int imax;
	int smax;
	int lmax;
	char obst;
	char empty;
	char square;
	int i;
	int j;
	int size;
	char **tab;
}                t_set_point;
char    **check(char **tab, struct s_set_point s);
int        checkcol(char **tab, struct s_set_point s);
int        checkline(char **tab, struct s_set_point s);
void    display(char **tab, struct s_set_point s);
#endif 
