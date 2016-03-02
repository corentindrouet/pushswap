/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:48:35 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/02 13:28:11 by cdrouet          ###   ########.fr       */
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
	char		action;
}				t_option;

typedef struct	s_all
{
	t_pile		*a;
	t_pile		*b;
	t_option	*p;
	int			*nbop;
}				t_all;

int				moitie_ind(t_pile a, int debut, int fin);
int				tri_a(t_all *res, int debut, int fin);
int				moitie(t_pile a);
int				cond(t_pile a, t_pile b);
int				verif_dec(t_pile a);
void			decroissant(t_pile *a, t_pile *b, int *nbop, t_option p);
void			swap_a_b(t_all *i);
void			rotate_a_b(t_all *j);
void			reverse_rotate_a_b(t_pile *a, t_pile *b,
					t_option *p, int *nbop);
int				verif_nbr(char *str);
int				verif_rank(t_pile a, int i);
int				verif_doublon(t_pile a);
int				test_bon(t_pile tab);
int				max_tab(t_pile tab);
int				min_tab(t_pile tab);
void			affiche_pile(t_pile p);
void			trace(t_pile a, t_pile b, t_option p);
int				init_option(int nb, char **argv, t_option *op, int *len);
int				croissant(t_all *i);//(t_pile *a, t_pile *b, int *nbop, t_option p);
void			swap_a(t_all *i);//(t_pile *tab, t_option *p, int *nbop);
void			push_a(t_pile *tab_a, t_pile *tab_b, t_option *p, int *nbop);
void			rotate_a(t_pile *tab_a, t_option *p, int *nbop);
void			reverse_rotate_a(t_pile *tab_a, t_option *p, int *nbop);
void			swap_b(t_pile *tab, t_option *p, int *nbop);
void			push_b(t_pile *tab_a, t_pile *tab_b, t_option *p, int *nbop);
void			rotate_b(t_pile *tab_b, t_option *p, int *nbop);
void			reverse_rotate_b(t_pile *tab_a, t_option *p, int *nbop);

#endif
