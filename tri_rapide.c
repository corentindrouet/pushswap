/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_rapide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:13:16 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/26 15:48:34 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	search_ind(t_pile a, int nb)
{
	while (--a.len >= 0)
		if (a.pile[a.len] == nb)
			return (a.len);
	return (-1);
}

int			moitie_ind(t_pile a, int debut, int fin)
{
	int		nb;
	int		i;
	int		j;

	i = debut;
	if (fin - debut <= 2)
		return (a.pile[fin - debut]);
	while (i < fin)
	{
		j = debut;
		nb = 0;
		while (j <= fin)
		{
			if (a.pile[i] < a.pile[j])
				nb++;
			j++;
		}
		if (nb == (a.len / 2))
			return (a.pile[i]);
		i++;
	}
	return (a.pile[(fin - debut)]);
}

static int	pass(t_pile a, int debut, int fin)
{
	while (debut++ < fin)
		if (a.pile[debut - 1] < a.pile[debut])
			return (0);
	return (1);
}

int		tri_a(t_all *res, int debut, int fin)
{
	int	base;
	int	ind;
	int	i;


	if (pass(*(res->a), debut, fin))
		return (1);
	base = moitie_ind(*(res->a), debut, fin);
	ft_printf("recur-%d-%d-%d\n", base, debut, fin);
	rotate_a(res->a, res->p, res->nbop);
	trace(*(res->a), *(res->b), *(res->p));
	i = debut;
	while (i++ <= fin)
	{
		if (res->a->pile[res->a->len - 1] < base)
			push_b(res->b, res->a, res->p, res->nbop);
		else
			rotate_a(res->a, res->p, res->nbop);
		trace(*(res->a), *(res->b), *(res->p));
	}
	while (res->a->pile[res->a->len - 1] != base)
		rotate_a(res->a, res->p, res->nbop);
		trace(*(res->a), *(res->b), *(res->p));
	if (res->a->pile[res->a->len - 1] < base)
		push_b(res->b, res->a, res->p, res->nbop);
		trace(*(res->a), *(res->b), *(res->p));
	while (res->b->len > 0)
		push_a(res->a, res->b, res->p, res->nbop);
		trace(*(res->a), *(res->b), *(res->p));
	ind = search_ind(*(res->a), base);
	tri_a(res, ind + 1, fin);
		trace(*(res->a), *(res->b), *(res->p));
	i = 0;
	while (res->a->pile[res->a->len - 1] != base)
	{
		rotate_a(res->a, res->p, res->nbop);
		trace(*(res->a), *(res->b), *(res->p));
		i++;
	}
	tri_a(res, i--, res->a->len - 1);
	while (i-- > 0)
		reverse_rotate_a(res->a, res->p, res->nbop);
		trace(*(res->a), *(res->b), *(res->p));
	return (1);
}
