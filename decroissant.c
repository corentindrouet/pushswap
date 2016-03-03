/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decroissant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:49:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/03 09:14:09 by cdrouet          ###   ########.fr       */
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

void	decroissant(t_all *i)
{
	while (i->a->len > 2)
	{
		push_b(i);
		if (i->b->len > 1)
			rotate_b(i);
	}
	swap_a(i);
	while (i->b->len > 0)
		push_a(i);
}

void	morc_tri_r(t_all *res, int debut, int fin, int base)
{
	int	i;
	int	ind;

	i = debut;
	ind = 0;
	while (i++ <= fin)
		if (res->a->pile[res->a->len - 1] < base)
			push_b(res);
		else
		{
			if (res->a->pile[res->a->len - 1] == base)
			{
				push_b(res);
				rotate_b(res);
			}
			else
			{
				rotate_a(res);
				ind++;
			}
		}
	if ((fin - debut) != (res->a->len + res->b->len - 1))
		while (ind-- > 0)
			reverse_rotate_a(res);
	reverse_rotate_b(res);
}
