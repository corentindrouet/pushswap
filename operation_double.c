/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:20:21 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/23 15:13:04 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_a_b(t_pile *a, t_pile *b, t_option *p, int *nbop)
{
	if (a->len > 1)
	{
		a->pile[a->len - 1] += a->pile[a->len - 2];
		a->pile[a->len - 2] = a->pile[a->len - 1] - a->pile[a->len - 2];
		a->pile[a->len - 1] = a->pile[a->len - 1] - a->pile[a->len - 2];
	}
	if (a->len > 1)
	{
		b->pile[b->len - 1] += b->pile[b->len - 2];
		b->pile[b->len - 2] = b->pile[b->len - 1] - b->pile[b->len - 2];
		b->pile[b->len - 1] = b->pile[b->len - 1] - b->pile[b->len - 2];
	}
	(*nbop)++;
	p->action++;
	if (p->color)
		ft_printf("{jaune}ss{eoc} ");
	else
		ft_printf("ss ");
}

void	rotate_a_b(t_pile *a, t_pile *b, t_option *p, int *nbop)
{
	int	tempo;
	int	i;

	i = a->len;
	if (i > 1)
	{
		tempo = a->pile[a->len - 1];
		while (--i > 0)
			a->pile[i] = a->pile[i - 1];
		a->pile[i] = tempo;
	}
	i = b->len;
	if (i > 1)
	{
		tempo = b->pile[b->len - 1];
		while (--i > 0)
			b->pile[i] = b->pile[i - 1];
		b->pile[i] = tempo;
	}
	(*nbop)++;
	if (p->color)
		ft_printf("{jaune}rr{eoc} ");
	else
		ft_printf("rr ");
	p->action++;
}

void	reverse_rotate_a_b(t_pile *a, t_pile *b, t_option *p, int *nbop)
{
	int tempo;
	int	i;

	if (a->len > 1)
	{
		tempo = a->pile[0];
		i = -1;
		while (++i < (a->len - 1))
			a->pile[i] = a->pile[i + 1];
		a->pile[i] = tempo;
	}
	if (b->len > 1)
	{
		tempo = b->pile[0];
		i = -1;
		while (++i < (b->len - 1))
			b->pile[i] = b->pile[i + 1];
		b->pile[i] = tempo;
	}
	(*nbop)++;
	if (p->color)
		ft_printf("{jaune}rrr{eoc} ");
	else
		ft_printf("rrr ");
	p->action++;
}
