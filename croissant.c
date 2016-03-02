/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   croissant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:57:11 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/02 14:30:46 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			cond(t_pile a, t_pile b)
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

static void	rsa(t_all *i)
{
	if (cond(*(i->a), *(i->b)) == 1 && i->a->pile[i->a->len - 1]
		== max_tab(*(i->a)) && i->b->pile[i->b->len - 1] == min_tab(*(i->b)))
		rotate_a_b(i);
	if (cond(*(i->a), *(i->b)) == 1 && i->a->pile[i->a->len - 1]
		!= max_tab(*(i->a)) && i->b->pile[i->b->len - 1] != min_tab(*(i->b)))
		swap_a_b(i);
	if ((cond(*(i->a), *(i->b)) == 1 || cond(*(i->a), *(i->b)) == 2)
		&& i->a->pile[i->a->len - 1] != max_tab(*(i->a))
			&& i->a->pile[i->a->len - 1] < i->a->pile[0])
		swap_a(i);
	if ((cond(*(i->a), *(i->b)) == 1 || cond(*(i->a), *(i->b)) == 3)
		&& i->b->pile[i->b->len - 1] != min_tab(*(i->a))
			&& i->b->pile[i->b->len - 1] > i->b->pile[0])
		swap_b(i);
	if ((cond(*(i->a), *(i->b)) == 1 || cond(*(i->a), *(i->b)) == 2)
		&& i->a->pile[i->a->len - 1] > i->a->pile[0])
		rotate_a(i);
	if ((cond(*(i->a), *(i->b)) == 1 || cond(*(i->a), *(i->b)) == 3)
		&& i->b->pile[i->b->len - 1] < i->b->pile[0])
		rotate_b(i);
}

int			croissant(t_all *i)
{
	while (test_bon(*(i->a)) || (!test_bon(*(i->a)) && i->b->len > 0))
	{
		if ((i->a->len >= 2 && (i->a->pile[i->a->len - 1]
			> i->a->pile[i->a->len - 2])) || (i->b->len >= 2
				&& i->b->pile[i->b->len - 1] < i->b->pile[i->b->len - 2]))
			rsa(i);
		if (i->a->len > 2 && (i->a->pile[0] < i->a->pile[i->a->len - 1]))
			reverse_rotate_a(i);
		if (i->b->len > 2 && (i->b->pile[0] == max_tab(*(i->b))
			|| ((i->b->len % 2) != 0
				&& i->b->pile[(i->b->len / 2)] == min_tab(*(i->b)))
					|| (verif_rank(*(i->b), i->b->pile[0]) == (i->b->len - 1))))
			reverse_rotate_b(i);
		if (!test_bon(*(i->a)) && i->b->len != 0 && i->p->action == 0)
			push_a(i);
		else if (test_bon(*(i->a)) && i->p->action == 0)
			push_b(i);
		i->p->action = 0;
	}
	return (1);
}
