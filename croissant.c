/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   croissant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:57:11 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/22 14:45:48 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	rsa(t_pile *a, t_option *p, int *nbop, t_pile *b)
{
	if ((a->pile[a->len - 1] > a->pile[a->len - 2])
		&& (b->pile[b->len - 1] < b->pile[b->len - 2]))
	{
		if (a->pile[a->len - 1] == max_tab(*a)
			&& b->pile[b->len - 1] == min_tab(*b))
			rotate_a_b(a, b, p);
	}
	if (a->pile[a->len - 1] == max_tab(*a))
		rotate_a(a, p);
	else
		swap_a(a, p);
	(*nbop)++;
	if (p->etape)
		trace(*a, *b, *p);
	if (b->pile[b->len - 1] == min_tab(*b))
		rotate_b(b, p);
	else
		swap_b(b, p);
	(*nbop)++;
	if (p->etape)
		trace(*a, *b, *p);
}

static void	rra(t_pile *a, t_pile *b, int *nbop, t_option *p)
{
	reverse_rotate_a(a, p);
	(*nbop)++;
	if (p->etape)
		trace(*a, *b, *p);
}

static void	rrb(t_pile *a, t_pile *b, int *nbop, t_option *p)
{
	reverse_rotate_b(b, p);
	(*nbop)++;
	if (p->etape)
		trace(*a, *b, *p);
}

int			croissant(t_pile *a, t_pile *b, int *nbop, t_option p)
{
	if (b->len == 0 && !test_bon(*a))
		return (1);
	if ((a->len >= 2 && (a->pile[a->len - 1] > a->pile[a->len - 2]))
		|| (b->len >= 2 && b->pile[b->len - 1] < b->pile[b->len - 2]))
		rsa(a, &p, nbop, b);
	if (a->len > 2 && (a->pile[0] == min_tab(*a)
		|| ((a->len % 2) != 0 && a->pile[(a->len / 2)] == max_tab(*a))
			|| (verif_rank(*a, a->pile[0]) == 2)))
		rra(a, b, nbop, &p);
	if (b->len > 2 && (b->pile[0] == max_tab(*b)
		|| ((b->len % 2) != 0 && b->pile[(b->len / 2)] == min_tab(*b))
			|| (verif_rank(*b, b->pile[0]) == (b->len - 1))))
		rrb(a, b, nbop, &p);
	if (!test_bon(*a) && b->len != 0 && p.action == 0)
		push_a(a, b, &p, nbop);
	else if (test_bon(*a) && p.action == 0)
		push_b(b, a, &p, nbop);
	if (p.etape && p.action == 0)
		trace(*a, *b, p);
	p.action = 0;
	croissant(a, b, nbop, p);
	return (1);
}
