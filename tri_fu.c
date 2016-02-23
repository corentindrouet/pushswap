/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:56:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/23 14:19:27 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	moitie(t_pile a)
{
	int		nb;
	int		i;
	int		j;

	i = 0;
	while (i < a.len)
	{
		j = 0;
		nb = 0;
		while (j < a.len)
		{
			if (j != i)
				if (a.pile[i] < a.pile[j])
					nb++;
			j++;
		}
		if (nb == (a.len / 2))
			return (a.pile[i]);
		i++;
	}
	return (-1);
}

static int	verif_inf(t_pile a, int nb)
{
	int	i;

	i = 0;
	while (i < a.len)
		if (a.pile[i++] <= nb)
			return (0);
	return (1);
}

static void	divis(t_pile *a, t_pile *b, t_option p, int *nbop)
{
	int	moit;

	moit = moitie(*a);
	while (!verif_inf(*a, moit))
	{
		if (a->pile[a->len - 1] <= moit)
			push_b(b, a, &p, nbop);
		else
			rotate_a(a, &p, nbop);
	}
}

void		fusion(t_pile *a, t_pile *b, t_option p, int *nbop)
{
	divis(a, b, p, nbop);
	croissant(a, b, nbop, p);
}
