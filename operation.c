/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:47:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/16 08:59:37 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(int *tab, int taille)
{
	if (taille <= 1)
		return ;
	tab[taille - 1] += tab[taille - 2];
	tab[taille - 2] = tab[taille - 1] - tab[taille - 2];
	tab[taille - 1] = tab[taille - 1] - tab[taille - 2];
}

void	push(int *tab1, int t1, int *tab2, int t2)
{
	if (t2 == 0)
		return ;
	tab1[t1] = tab2[t2];
}

void	rotate(int *tab1, int taille)
{
	int	tempo;

	tempo = tab1[taille - 1];
	while (--taille > 0)
		tab[taille] = tab[taille - 1];
	tab[taille] = tempo;
}
