/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:56:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/26 11:08:14 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			moitie(t_pile a)
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
	int		c;

	divis(a, b, p, nbop);
	ft_printf("\nok\n");
	while (!verif_dec(*b) || test_bon(*a))
	{
		c = cond(*a, *b);
		if (c == 1)
			swap_a_b(a, b, &p, nbop);
		else if (c == 2)
			swap_a(a, &p, nbop);
		else if (c == 3)
			swap_b(b, &p, nbop);
		else
		{
			if (a->len >= 2 && a->pile[a->len - 1] > a->pile[0]
				&& b->len >= 2 && b->pile[b->len - 1] < b->pile[0])
				rotate_a_b(a,b, &p, nbop);
			else if (a->len >= 2 && a->pile[a->len - 1] > a->pile[0])
				rotate_a(a, &p, nbop);
			else if (b->len >= 2 && b->pile[b->len - 1] < b->pile[0])
				rotate_b(b, &p, nbop);
			else
			{
				if (a->len >= 2 && a->pile[a->len - 1] < a->pile[0]
					&& b->len >= 2 && b->pile[b->len - 1] > b->pile [0])
					reverse_rotate_a_b(a, b, &p, nbop);
				else if (a->len >= 2 && a->pile[a->len - 1] < a->pile[0])
					reverse_rotate_a(a, &p, nbop);
				else if (b->len >= 2 && b->pile[b->len - 1] > b->pile[0])
					reverse_rotate_b(b, &p, nbop);
				else
					break ;
			}
		}
		if (p.etape)
			trace(*a, *b, p);
	}
	while (b->len > 0)
		push_a(a, b, &p, nbop);
}
