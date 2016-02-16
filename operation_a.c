/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:47:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/16 13:03:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_a(int *tab, int taille)
{
	if (taille <= 1)
		return ;
	tab[taille - 1] += tab[taille - 2];
	tab[taille - 2] = tab[taille - 1] - tab[taille - 2];
	tab[taille - 1] = tab[taille - 1] - tab[taille - 2];
	ft_printf("{rouge}sa{eoc}");
}

void	push_a(int *tab1, int *t1, int *tab2, int *t2)
{
	if ((*t2) == 0)
		return ;
	tab1[(*t1)++] = tab2[--(*t2)];
	ft_printf("{rouge}pa{eoc}");
}

void	rotate_a(int *tab1, int taille)
{
	int	tempo;

	if (taille <= 1)
		return ;
	tempo = tab1[taille - 1];
	while (--taille > 0)
		tab1[taille] = tab1[taille - 1];
	tab1[taille] = tempo;
	ft_printf("{rouge}ra{eoc}");
}

void	reverse_rotate_a(int *tab1, int taille)
{
	int tempo;
	int	i;

	if (taille <= 1)
		return ;
	tempo = tab1[0];
	i = -1;
	while (++i < (taille - 1))
		tab1[i] = tab1[i + 1];
	tab1[i] = tempo;
	ft_printf("{rouge}rra{eoc}");
}
