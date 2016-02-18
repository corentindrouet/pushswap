/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:48:35 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/18 09:48:45 by cdrouet          ###   ########.fr       */
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

int				croissant(t_pile *a, t_pile *b, int *nbop);
void			swap_a(t_pile *tab);
void			push_a(t_pile *tab_a, t_pile *tab_b);
void			rotate_a(t_pile *tab_a);
void			reverse_rotate_a(t_pile *tab_a);
void			swap_b(t_pile *tab);
void			push_b(t_pile *tab_a, t_pile *tab_b);
void			rotate_b(t_pile *tab_b);
void			reverse_rotate_b(t_pile *tab_a);

#endif
