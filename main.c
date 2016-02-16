/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:19:32 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/16 14:27:32 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		test_bon(int *tab, int nbr)
{
	while (--nbr > 0)
		if (tab[nbr] > tab[nbr - 1])
			return (1);
	return (0);
}

void	croissant(int *tab, int *nbr)
{
	int	*b;
	int	nbb;
	int	i;
	int	a;
	int	nbop;

	b = (int*)malloc(sizeof(int) * (*nbr));
	nbb = 0;
	nbop = 0;
	while (test_bon(tab, *nbr))
	{
		i = *nbr;
		while (--i > 0)
			if (tab[i] > tab[i - 1])
			{
				a = (*nbr) - 1;
				while (a-- > i)
				{
					nbop++;
					push_b(b, &nbb, tab, nbr);
					ft_printf(" ");
				}
				swap_a(tab, *nbr);
				nbop++;
				ft_printf(" ");
				while (nbb)
				{
					push_a(tab, nbr, b, &nbb);
					nbop++;
					if (tab[(*nbr) - 1] > tab[(*nbr) - 2])
					{
						ft_printf(" ");
						swap_a(tab, *nbr);
						nbop++;
					}
					if (nbb != 0)
						ft_printf(" ");
				}
				ft_printf("\n");
			}
	}
	ft_printf("%d\n", nbop);
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
