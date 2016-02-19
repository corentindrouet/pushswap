/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:48:35 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/19 09:39:42 by cdrouet          ###   ########.fr       */
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
	char		doublon;
	char		action;
}				t_option;

int				verif_rank(t_pile a, int i);
int				verif_doublon(t_pile a);
int				test_bon(t_pile tab);
int				max_tab(t_pile tab);
int				min_tab(t_pile tab);
void			affiche_pile(t_pile p);
void			trace(t_pile a, t_pile b, t_option p);
int				init_option(int nb, char **argv, t_option *op, int *len);
int				croissant(t_pile *a, t_pile *b, int *nbop, t_option p);
void			swap_a(t_pile *tab, t_option *p);
void			push_a(t_pile *tab_a, t_pile *tab_b, t_option *p, int *nbop);
void			rotate_a(t_pile *tab_a, t_option *p);
void			reverse_rotate_a(t_pile *tab_a, t_option *p);
void			swap_b(t_pile *tab, t_option *p);
void			push_b(t_pile *tab_a, t_pile *tab_b, t_option *p, int *nbop);
void			rotate_b(t_pile *tab_b, t_option *p);
void			reverse_rotate_b(t_pile *tab_a, t_option *p);

#endif
