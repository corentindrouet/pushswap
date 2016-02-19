/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:47:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/19 08:27:07 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_a(t_pile *tab, t_option *p)
{
	if (tab->len <= 1)
		return ;
	tab->pile[tab->len - 1] += tab->pile[tab->len - 2];
	tab->pile[tab->len - 2] = tab->pile[tab->len - 1] - tab->pile[tab->len - 2];
	tab->pile[tab->len - 1] = tab->pile[tab->len - 1] - tab->pile[tab->len - 2];
	p->action++;
	if (p->color)
		ft_printf("{rouge}sa{eoc} ");
	else
		ft_printf("sa ");
}

void	push_a(t_pile *tab_a, t_pile *tab_b, t_option *p)
{
	if ((tab_b->len) == 0)
		return ;
	tab_a->pile[tab_a->len++] = tab_b->pile[--tab_b->len];
	p->action++;
	if (p->color)
		ft_printf("{rouge}pa{eoc} ");
	else
		ft_printf("pa ");
}

void	rotate_a(t_pile *tab_a, t_option *p)
{
	int	tempo;
	int	i;

	i = tab_a->len;
	if (i <= 1)
		return ;
	tempo = tab_a->pile[tab_a->len - 1];
	while (--i > 0)
		tab_a->pile[i] = tab_a->pile[i - 1];
	tab_a->pile[i] = tempo;
	p->action++;
	if (p->color)
		ft_printf("{rouge}ra{eoc} ");
	else
		ft_printf("ra ");
}

void	reverse_rotate_a(t_pile *tab_a, t_option *p)
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
	if (p->color)
		ft_printf("{rouge}rra{eoc} ");
	else
		ft_printf("rra ");
}
