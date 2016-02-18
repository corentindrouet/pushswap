/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:19:32 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/18 13:59:40 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		test_bon(t_pile tab)
{
	while (--tab.len > 0)
		if (tab.pile[tab.len] > tab.pile[tab.len - 1])
			return (1);
	return (0);
}

int		max_tab(t_pile tab)
{
	int	max;

	max = tab.pile[--tab.len];
	while (--tab.len >= 0)
		if (tab.pile[tab.len] > max)
			max = tab.pile[tab.len];
	return (max);
}

int		min_tab(t_pile tab)
{
	int	min;

	min = tab.pile[--tab.len];
	while (--tab.len >= 0)
		if (tab.pile[tab.len] < min)
			min = tab.pile[tab.len];
	return (min);
}

int		main(int argc, char **argv)
{
	t_pile		a;
	t_pile		b;
	t_option	p;
	int			nbop;
	int			doub;

	if (argc == 1)
		return (0);
	a.len = 0;
	if (!init_option(argc, argv, &p, &(a.len)))
		ft_printf("Error\n");
	a.pile = (int*)malloc(sizeof(int) * a.len);
	b.pile = (int*)malloc(sizeof(int) * a.len);
	b.len = 0;
	argc = -1;
	doub = 0;
	while (++argc < a.len)
	{
		if (!verif_doublon(a, argc, argv))
			doub++;
		a.pile[a.len - argc - 1] = ft_atoi(argv[argc + 1]);
	}
	if (doub != 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	nbop = 0;
	croissant(&a, &b, &nbop, p);
	argc = 0;
	if (p.nbop)
		ft_printf("\noperation effectue : %d", nbop);
	if (p.finalpile)
		affiche_pile(a);
	return (0);
}
