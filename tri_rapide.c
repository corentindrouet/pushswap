/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_rapide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:13:16 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/03 09:24:26 by cdrouet          ###   ########.fr       */
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

static int	morc(t_all *res, int base)
{
	int	i;

	i = 0;
	while (res->a->pile[res->a->len - 1] != base)
	{
		rotate_a(res);
		i++;
	}
	rotate_a(res);
	i++;
	return (i);
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
	morc_tri_r(res, debut, fin, base);
	while (res->b->len > 0)
		push_a(res);
	ind = search_ind(*(res->a), base);
	if (!pass(*(res->a), ind + 1, fin))
		tri_a(res, ind + 1, fin);
	if (pass(*(res->a), debut, fin))
		return (1);
	i = morc(res, base);
	if (!pass(*(res->a), debut + i, res->a->len - 1))
		tri_a(res, debut + i, res->a->len - 1);
	while (i-- > 0)
		reverse_rotate_a(res);
	return (1);
}
