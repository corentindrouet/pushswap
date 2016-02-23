/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decroissant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:49:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/23 13:09:12 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		verif_dec(t_pile a)
{
	while (--a.len > 0)
		if (a.pile[a.len] < a.pile[a.len - 1])
			return (0);
	return (1);
}

void	decroissant(t_pile *a, t_pile *b, int *nbop, t_option p)
{
	while (a->len > 2)
	{
		push_b(b, a, &p, nbop);
		if (b->len > 1)
			rotate_b(b, &p, nbop);
	}
	swap_a(a, &p, nbop);
	while (b->len > 0)
		push_a(a, b, &p, nbop);
}
