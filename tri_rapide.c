/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_rapide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:13:16 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/02 11:56:45 by cdrouet          ###   ########.fr       */
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
	while (i <= fin)
	{
		j = debut;
		nb = 0;
		while (j <= fin)
		{
			if (a.pile[i] < a.pile[j])
				nb++;
			j++;
		}
		if (nb == ((fin - debut + 1) / 2))
			return (a.pile[i]);
		i++;
	}
	return (a.pile[(debut)]);
}

static int	pass(t_pile a, int debut, int fin)
{
	while (debut++ < fin)
		if (a.pile[debut - 1] < a.pile[debut])
			return (0);
	return (1);
}

int			tri_a(t_all *res, int debut, int fin)
{
	int	base;
	int	ind;
	int	i;

	if ((fin - debut) == 1)
		if (!pass(*(res->a), debut, fin))
			swap_a(res);
	if (pass(*(res->a), debut, fin))
		return (1);
	base = moitie_ind(*(res->a), debut, fin);
	i = debut;
	ind = 0;
	while (i++ <= fin)
	{
		if (res->a->pile[res->a->len - 1] < base)
			push_b(res->b, res->a, res->p, res->nbop);
		else
		{
			if (res->a->pile[res->a->len - 1] == base)
			{
				push_b(res->b, res->a, res->p, res->nbop);
				rotate_b(res->b, res->p, res->nbop);
			}
			else
			{
				rotate_a(res->a, res->p, res->nbop);
				ind++;
			}
		}
	}
	if ((fin - debut) != (res->a->len + res->b->len - 1))
		while (ind-- > 0)
			reverse_rotate_a(res->a, res->p, res->nbop);
	reverse_rotate_b(res->b, res->p, res->nbop);
	while (res->b->len > 0)
		push_a(res->a, res->b, res->p, res->nbop);
	ind = search_ind(*(res->a), base);
	if (!pass(*(res->a), ind + 1, fin))
		tri_a(res, ind + 1, fin);
	if (pass(*(res->a), debut, fin))
		return (1);
	i = 0;
	while (res->a->pile[res->a->len - 1] != base)
	{
		rotate_a(res->a, res->p, res->nbop);
		i++;
	}
	rotate_a(res->a, res->p, res->nbop);
	i++;
	if (!pass(*(res->a), debut + i, res->a->len - 1))
		tri_a(res, debut + i, res->a->len - 1);
	while (i-- > 0)
		reverse_rotate_a(res->a, res->p, res->nbop);
	return (1);
}
