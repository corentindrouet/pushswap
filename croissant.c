/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   croissant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:57:11 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/18 13:36:02 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	rsa(t_pile *a, t_option p, int *nbop, t_pile *b)
{
	if (a->pile[a->len - 1] == max_tab(*a))
		rotate_a(a, p);
	else
		swap_a(a, p);
	(*nbop)++;
	if (p.etape)
		trace(*a, *b, p);
}

static void	rsb(t_pile *a, t_option p, int *nbop, t_pile *b)
{
	if (b->pile[b->len - 1] == min_tab(*b))
		rotate_b(b, p);
	else
		swap_b(b, p);
	(*nbop)++;
	if (p.etape)
		trace(*a, *b, p);
}

static void	rra(t_pile *a, t_pile *b, int *nbop, t_option p)
{
	reverse_rotate_a(a, p);
	(*nbop)++;
	if (p.etape)
		trace(*a, *b, p);
}

static void	rrb(t_pile *a, t_pile *b, int *nbop, t_option p)
{
	reverse_rotate_b(b, p);
	(*nbop)++;
	if (p.etape)
		trace(*a, *b, p);
}

int			croissant(t_pile *a, t_pile *b, int *nbop, t_option p)
{
	if (b->len == 0 && !test_bon(*a))
		return (1);
	if (a->len >= 2 && (a->pile[a->len - 1] > a->pile[a->len - 2]))
		rsa(a, p, nbop, b);
	if (b->len >= 2 && b->pile[b->len - 1] < b->pile[b->len - 2])
		rsb(a, p, nbop, b);
	if (a->len > 2 && a->pile[0] == min_tab(*a))
		rra(a, b, nbop, p);
	if (b->len > 2 && b->pile[0] == max_tab(*b))
		rrb(a, b, nbop, p);
	if (!test_bon(*a) && b->len != 0)
		push_a(a, b, p);
	else if (test_bon(*a))
		push_b(b, a, p);
	(*nbop)++;
	if (p.etape)
		trace(*a, *b, p);
	croissant(a, b, nbop, p);
	return (1);
}
