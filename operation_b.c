/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:47:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/02 14:31:56 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		verif_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

void	swap_b(t_all *i)
{
	if (i->b->len <= 1)
		return ;
	i->b->pile[i->b->len - 1] += i->b->pile[i->b->len - 2];
	i->b->pile[i->b->len - 2] =
		i->b->pile[i->b->len - 1] - i->b->pile[i->b->len - 2];
	i->b->pile[i->b->len - 1] =
		i->b->pile[i->b->len - 1] - i->b->pile[i->b->len - 2];
	i->p->action++;
	(*(i->nbop))++;
	if (i->p->color)
		ft_printf("{cyan}sb{eoc} ");
	else
		ft_printf("sb ");
	if (i->p->etape)
		trace(*(i->a), *(i->b), *(i->p));
}

void	push_b(t_all *i)
{
	if ((i->a->len) == 0)
		return ;
	i->b->pile[i->b->len++] = i->a->pile[--i->a->len];
	(*(i->nbop))++;
	if (i->p->color)
		ft_printf("{cyan}pb{eoc} ");
	else
		ft_printf("pb ");
	if (i->p->etape)
		trace(*(i->a), *(i->b), *(i->p));
}

void	rotate_b(t_all *j)
{
	int	tempo;
	int	i;

	i = j->b->len;
	if (j->b->len <= 1)
		return ;
	tempo = j->b->pile[j->b->len - 1];
	while (--i > 0)
		j->b->pile[i] = j->b->pile[i - 1];
	j->b->pile[i] = tempo;
	j->p->action++;
	(*(j->nbop))++;
	if (j->p->color)
		ft_printf("{cyan}rb{eoc} ");
	else
		ft_printf("rb ");
	if (j->p->etape)
		trace(*(j->a), *(j->b), *(j->p));
}

void	reverse_rotate_b(t_all *j)
{
	int tempo;
	int	i;

	if (j->b->len <= 1)
		return ;
	tempo = j->b->pile[0];
	i = -1;
	while (++i < (j->b->len - 1))
		j->b->pile[i] = j->b->pile[i + 1];
	j->b->pile[i] = tempo;
	j->p->action++;
	(*(j->nbop))++;
	if (j->p->color)
		ft_printf("{cyan}rrb{eoc} ");
	else
		ft_printf("rrb ");
	if (j->p->etape)
		trace(*(j->a), *(j->b), *(j->p));
}
