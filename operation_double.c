/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:20:21 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/02 13:28:18 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_a_b(t_all *i)
{
	if (i->a->len > 1)
	{
		i->a->pile[i->a->len - 1] += i->a->pile[i->a->len - 2];
		i->a->pile[i->a->len - 2] = i->a->pile[i->a->len - 1] - i->a->pile[i->a->len - 2];
		i->a->pile[i->a->len - 1] = i->a->pile[i->a->len - 1] - i->a->pile[i->a->len - 2];
	}
	if (i->a->len > 1)
	{
		i->b->pile[i->b->len - 1] += i->b->pile[i->b->len - 2];
		i->b->pile[i->b->len - 2] = i->b->pile[i->b->len - 1] - i->b->pile[i->b->len - 2];
		i->b->pile[i->b->len - 1] = i->b->pile[i->b->len - 1] - i->b->pile[i->b->len - 2];
	}
	(*(i->nbop))++;
	i->p->action++;
	if (i->p->color)
		ft_printf("{jaune}ss{eoc} ");
	else
		ft_printf("ss ");
	if (i->p->etape)
		trace(*(i->a), *(i->b), *(i->p));
}

void	rotate_a_b(t_all *j)
{
	int	tempo;
	int	i;

	i = j->a->len;
	if (i > 1)
	{
		tempo = j->a->pile[j->a->len - 1];
		while (--i > 0)
			j->a->pile[i] = j->a->pile[i - 1];
		j->a->pile[i] = tempo;
	}
	i = j->b->len;
	if (i > 1)
	{
		tempo = j->b->pile[j->b->len - 1];
		while (--i > 0)
			j->b->pile[i] = j->b->pile[i - 1];
		j->b->pile[i] = tempo;
	}
	(*(j->nbop))++;
	if (j->p->color)
		ft_printf("{jaune}rr{eoc} ");
	else
		ft_printf("rr ");
	j->p->action++;
	if (j->p->etape)
		trace(*(j->a), *(j->b), *(j->p));
}

void	reverse_rotate_a_b(t_all *j)
{
	int tempo;
	int	i;

	if (j->a->len > 1)
	{
		tempo = j->a->pile[0];
		i = -1;
		while (++i < (j->a->len - 1))
			j->a->pile[i] = j->a->pile[i + 1];
		j->a->pile[i] = tempo;
	}
	if (j->b->len > 1)
	{
		tempo = j->b->pile[0];
		i = -1;
		while (++i < (j->b->len - 1))
			j->b->pile[i] = j->b->pile[i + 1];
		j->b->pile[i] = tempo;
	}
	(*(j->nbop))++;
	if (j->p->color)
		ft_printf("{jaune}rrr{eoc} ");
	else
		ft_printf("rrr ");
	j->p->action++;
	if (j->p->etape)
		trace(*(j->a), *(j->b), *(j->p));
}
