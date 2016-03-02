/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:47:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/02 13:49:19 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		verif_rank(t_pile a, int i)
{
	int	j;

	j = 0;
	while (--a.len >= 0)
		if (a.pile[a.len] <= i)
			j++;
	return (j);
}

void	swap_a(t_all *i)
{
	if (i->a->len <= 1)
		return ;
	i->a->pile[i->a->len - 1] += i->a->pile[i->a->len - 2];
	i->a->pile[i->a->len - 2] = i->a->pile[i->a->len - 1] - i->a->pile[i->a->len - 2];
	i->a->pile[i->a->len - 1] = i->a->pile[i->a->len - 1] - i->a->pile[i->a->len - 2];
	i->p->action++;
	(*(i->nbop))++;
	if (i->p->color)
		ft_printf("{rouge}sa{eoc} ");
	else
		ft_printf("sa ");
	if (i->p->etape)
		trace(*(i->a), *(i->b), *(i->p));
}

void	push_a(t_all *i)
{
	if ((i->b->len) == 0)
		return ;
	i->a->pile[i->a->len++] = i->b->pile[--i->b->len];
	(*(i->nbop))++;
	if (i->p->color)
		ft_printf("{rouge}pa{eoc} ");
	else
		ft_printf("pa ");
	if (i->p->etape)
		trace(*(i->a), *(i->b), *(i->p));
}

void	rotate_a(t_all *j)
{
	int	tempo;
	int	i;

	i = j->a->len;
	if (i <= 1)
		return ;
	tempo = j->a->pile[j->a->len - 1];
	while (--i > 0)
		j->a->pile[i] = j->a->pile[i - 1];
	j->a->pile[i] = tempo;
	j->p->action++;
	(*(j->nbop))++;
	if (j->p->color)
		ft_printf("{rouge}ra{eoc} ");
	else
		ft_printf("ra ");
	if (j->p->etape)
		trace(*(j->a), *(j->b), *(j->p));
}

void	reverse_rotate_a(t_all *j)
{
	int tempo;
	int	i;

	if (j->a->len <= 1)
		return ;
	tempo = j->a->pile[0];
	i = -1;
	while (++i < (j->a->len - 1))
		j->a->pile[i] = j->a->pile[i + 1];
	j->a->pile[i] = tempo;
	j->p->action++;
	(*(j->nbop))++;
	if (j->p->color)
		ft_printf("{rouge}rra{eoc} ");
	else
		ft_printf("rra ");
	if (j->p->etape)
		trace(*(j->a), *(j->b), *(j->p));
}
