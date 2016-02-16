/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:19:32 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/16 10:56:46 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	croissant(int *tab, int *nbr)
{
	int	*b;
	int	nbb;

	b = (int*)malloc(sizeof(int) * (*nbr));
	nbb = 0;
	swap_a(tab, *nbr);
	push_b(b, &nbb, tab, nbr);
	push_b(b, &nbb, tab, nbr);
	push_b(b, &nbb, tab, nbr);
	swap_a(tab, *nbr);
	push_a(tab, nbr, b, &nbb);
	push_a(tab, nbr, b, &nbb);
	push_a(tab, nbr, b, &nbb);
	free(b);
}

int		main(int argc, char **argv)
{
	int		*tab;
	int		nbr;

	if (argc == 1)
		return (0);
	nbr = 0;
	while (--argc > 0)
		if (!ft_strisdigit(argv[argc]))
			ft_printf("Error\n");
		else
			nbr++;
	tab = (int*)malloc(sizeof(int) * nbr);
	argc = -1;
	while (++argc < nbr)
		tab[nbr - argc - 1] = ft_atoi(argv[argc + 1]);
	croissant(tab, &nbr);
	argc = 0;
	while (argc < nbr)
		ft_printf("%d ", tab[argc++]);
	return (0);
}
