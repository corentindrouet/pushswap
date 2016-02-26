/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   croissant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:57:11 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/23 15:14:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	cond(t_pile a, t_pile b)
{
	if (a.len >= 2 && a.pile[a.len - 1] > a.pile[a.len - 2]
			&& b.len >= 2 && b.pile[b.len - 1] < b.pile[b.len - 2])
		return (1);
	else if (a.len >= 2 && a.pile[a.len - 1] > a.pile[a.len - 2])
		return (2);
	else if (b.len >= 2 && b.pile[b.len - 1] < b.pile[b.len - 2])
		return (3);
	return (0);
}

static void	rsa(t_pile *a, t_option *p, int *nbop, t_pile *b)
{
	if (cond(*a, *b) == 1 && a->pile[a->len - 1] == max_tab(*a)
			&& b->pile[b->len - 1] == min_tab(*b))
		rotate_a_b(a, b, p, nbop);
	if (cond(*a, *b) == 1 && a->pile[a->len - 1] != max_tab(*a)
			&& b->pile[b->len - 1] != min_tab(*b))
		swap_a_b(a, b, p, nbop);
	if ((cond(*a, *b) == 1 || cond(*a, *b) == 2) && a->pile[a->len - 1] != max_tab(*a)
		&& a->pile[a->len - 1] < a->pile[0])
		swap_a(a, p, nbop);
	if ((cond(*a, *b) == 1 || cond(*a, *b) == 3) && b->pile[b->len - 1] != min_tab(*a)
		&& b->pile[b->len - 1] > b->pile[0])
		swap_b(b, p, nbop);
	if ((cond(*a, *b) == 1 || cond(*a, *b) == 2) && a->pile[a->len - 1] > a->pile[0])
		rotate_a(a, p, nbop);
	if ((cond(*a, *b) == 1 || cond(*a, *b) == 3) && b->pile[b->len - 1] < b->pile[0])
		rotate_b(b, p, nbop);
	if (p->etape)
		trace(*a, *b, *p);
}

static void	rra(t_pile *a, t_pile *b, int *nbop, t_option *p)
{
	reverse_rotate_a(a, p, nbop);
	if (p->etape)
		trace(*a, *b, *p);
}

static void	rrb(t_pile *a, t_pile *b, int *nbop, t_option *p)
{
	reverse_rotate_b(b, p, nbop);
	if (p->etape)
		trace(*a, *b, *p);
}

int			croissant(t_pile *a, t_pile *b, int *nbop, t_option p)
{
	while (test_bon(*a) || (!test_bon(*a) && b->len > 0))
	{
		if ((a->len >= 2 && (a->pile[a->len - 1] > a->pile[a->len - 2]))
			|| (b->len >= 2 && b->pile[b->len - 1] < b->pile[b->len - 2]))
			rsa(a, &p, nbop, b);
		if (a->len > 2 && (a->pile[0] < a->pile[a->len - 1]))
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
	}
	return (1);
}
