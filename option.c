/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:59:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/03 09:18:27 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	init_op(t_option *op)
{
	op->color = 0;
	op->nbop = 0;
	op->finalpile = 0;
	op->etape = 0;
}

int			init_option(int nb, char **ar, t_option *op, int *len)
{
	init_op(op);
	while (--nb > 0)
		if (!ft_strisdigit(ar[nb]))
		{
			if (!ft_strcmp(ar[nb], "-c") || !ft_strcmp(ar[nb], "-C"))
				op->color++;
			else if (!ft_strcmp(ar[nb], "-v") || !ft_strcmp(ar[nb], "-V"))
				op->etape++;
			else if (!ft_strcmp(ar[nb], "-f") || !ft_strcmp(ar[nb], "-F"))
				op->finalpile++;
			else if (!ft_strcmp(ar[nb], "-o") || !ft_strcmp(ar[nb], "-O"))
				op->nbop++;
			else
				return (0);
		}
		else
		{
			if (!verif_nbr(ar[nb])
				|| ft_atol(ar[nb]) > 2147483647
					|| ft_atol(ar[nb]) < -2147483648 || ft_strlen(ar[nb]) > 13)
				return (0);
			else
				(*len)++;
		}
	return (1);
}

int			verif_doublon(t_pile a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a.len)
	{
		j = 0;
		while ((i + ++j) < a.len)
			if (a.pile[i] == a.pile[i + j])
				return (0);
	}
	return (1);
}

void		affiche_pile(t_pile p)
{
	int	i;

	i = 0;
	ft_printf("\npile finale : ");
	while (i < p.len)
		ft_printf("%d ", p.pile[i++]);
}

void		trace(t_pile a, t_pile b, t_option p)
{
	int	i;

	if (p.color)
		ft_printf("{rouge}");
	ft_printf("\npile_a : ");
	i = -1;
	while (++i < a.len)
		ft_printf("%d ", a.pile[i]);
	if (p.color)
		ft_printf("{eoc}");
	ft_printf("\n");
	if (p.color)
		ft_printf("{cyan}");
	ft_printf("pile_b : ");
	i = -1;
	while (++i < b.len)
		ft_printf("%d ", b.pile[i]);
	if (p.color)
		ft_printf("{eoc}");
	ft_printf("\n\n");
}
