/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:47:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/02 12:55:25 by cdrouet          ###   ########.fr       */
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
	i->b->pile[i->b->len - 2] = i->b->pile[i->b->len - 1] - i->b->pile[i->b->len - 2];
	i->b->pile[i->b->len - 1] = i->b->pile[i->b->len - 1] - i->b->pile[i->b->len - 2];
	i->p->action++;
	(*(i->nbop))++;
	if (i->p->color)
		ft_printf("{cyan}sb{eoc} ");
	else
		ft_printf("sb ");
	if (i->p->etape)
		trace(*(i->a), *(i->b), *(i->p));
}

void	push_b(t_pile *tab_a, t_pile *tab_b, t_option *p, int *nbop)
{
	if ((tab_b->len) == 0)
		return ;
	tab_a->pile[tab_a->len++] = tab_b->pile[--tab_b->len];
	(*nbop)++;
	if (p->color)
		ft_printf("{cyan}pb{eoc} ");
	else
		ft_printf("pb ");
}

void	rotate_b(t_pile *tab_b, t_option *p, int *nbop)
{
	int	tempo;
	int	i;

	i = tab_b->len;
	if (tab_b->len <= 1)
		return ;
	tempo = tab_b->pile[tab_b->len - 1];
	while (--i > 0)
		tab_b->pile[i] = tab_b->pile[i - 1];
	tab_b->pile[i] = tempo;
	p->action++;
	(*nbop)++;
	if (p->color)
		ft_printf("{cyan}rb{eoc} ");
	else
		ft_printf("rb ");
}

void	reverse_rotate_b(t_pile *tab_a, t_option *p, int *nbop)
{
	int tempo;
	int	i;

	if (tab_a->len <= 1)
		return ;
	tempo = tab_a->pile[0];
	i = -1;
	while (++i < (tab_a->len - 1))
		tab_a->pile[i] = tab_a->pile[i + 1];
	tab_a->pile[i] = tempo;
	p->action++;
	(*nbop)++;
	if (p->color)
		ft_printf("{cyan}rrb{eoc} ");
	else
		ft_printf("rrb ");
}
