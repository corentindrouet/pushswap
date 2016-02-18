/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:47:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/18 11:50:55 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_b(t_pile *tab, t_option p)
{
	if (tab->len <= 1)
		return ;
	tab->pile[tab->len - 1] += tab->pile[tab->len - 2];
	tab->pile[tab->len - 2] = tab->pile[tab->len - 1] - tab->pile[tab->len - 2];
	tab->pile[tab->len - 1] = tab->pile[tab->len - 1] - tab->pile[tab->len - 2];
	if (p.color)
		ft_printf("{cyan}sb{eoc} ");
	else
		ft_printf("sb ");
}

void	push_b(t_pile *tab_a, t_pile *tab_b, t_option p)
{
	if ((tab_b->len) == 0)
		return ;
	tab_a->pile[tab_a->len++] = tab_b->pile[--tab_b->len];
	if (p.color)
		ft_printf("{cyan}pb{eoc} ");
	else
		ft_printf("pb ");
}

void	rotate_b(t_pile *tab_b, t_option p)
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
	if (p.color)
		ft_printf("{cyan}rb{eoc} ");
	else
		ft_printf("rb ");
}

void	reverse_rotate_b(t_pile *tab_a, t_option p)
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
	if (p.color)
		ft_printf("{cyan}rrb{eoc} ");
	else
		ft_printf("rrb ");
}
