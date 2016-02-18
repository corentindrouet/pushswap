/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:48:35 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/18 11:44:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include "libft/libft.h"

typedef struct	s_pile
{
	int			*pile;
	int			len;
}				t_pile;

typedef struct	s_option
{
	char		color;
	char		nbop;
	char		finalpile;
	char		etape;
}				t_option;

int				init_option(int nb, char **argv, t_option *op, int *len);
int				croissant(t_pile *a, t_pile *b, int *nbop, t_option p);
void			swap_a(t_pile *tab, t_option p);
void			push_a(t_pile *tab_a, t_pile *tab_b, t_option p);
void			rotate_a(t_pile *tab_a, t_option p);
void			reverse_rotate_a(t_pile *tab_a, t_option p);
void			swap_b(t_pile *tab, t_option p);
void			push_b(t_pile *tab_a, t_pile *tab_b, t_option p);
void			rotate_b(t_pile *tab_b, t_option p);
void			reverse_rotate_b(t_pile *tab_a, t_option p);

#endif
