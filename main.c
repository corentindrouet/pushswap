/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:19:32 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/19 12:56:20 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			test_bon(t_pile tab)
{
	while (--tab.len > 0)
		if (tab.pile[tab.len] > tab.pile[tab.len - 1])
			return (1);
	return (0);
}

int			max_tab(t_pile tab)
{
	int	max;

	max = tab.pile[--tab.len];
	while (--tab.len >= 0)
		if (tab.pile[tab.len] > max)
			max = tab.pile[tab.len];
	return (max);
}

int			min_tab(t_pile tab)
{
	int	min;

	min = tab.pile[--tab.len];
	while (--tab.len >= 0)
		if (tab.pile[tab.len] < min)
			min = tab.pile[tab.len];
	return (min);
}

static int	error_msg(char *str)
{
	ft_printf(str);
	return (0);
}

int			main(int argc, char **argv)
{
	t_pile		a;
	t_pile		b;
	t_option	p;
	int			nbop;

	if (argc == 1)
		return (error_msg("No calcul to be done for this one\n"));
	a.len = 0;
	if (!init_option(argc, argv, &p, &(a.len)))
		return (error_msg("Error\n"));
	a.pile = (int*)malloc(sizeof(int) * a.len);
	b.pile = (int*)malloc(sizeof(int) * a.len);
	b.len = 0;
	argc = -1;
	while (++argc < a.len)
		a.pile[a.len - argc - 1] = ft_atoi(argv[argc + 1]);
	if (!verif_doublon(a) || !test_bon(a))
		return (error_msg((!test_bon(a)) ? "Already done\n" : "Error\n"));
	nbop = 0;
	croissant(&a, &b, &nbop, p);
	if (p.nbop)
		ft_printf("\noperation effectue : %d", nbop);
	if (p.finalpile)
		affiche_pile(a);
	return (0);
}
