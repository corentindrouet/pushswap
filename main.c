/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:19:32 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/03 08:42:14 by cdrouet          ###   ########.fr       */
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
	t_all		i;
	int			nbop;

	if (argc == 1)
		return (error_msg("No calcul to be done for this one\n"));
	a.len = 0;
	if (!init_option(argc, argv, &p, &(a.len)))
		return (error_msg("Error\n"));
	a.pile = (int*)malloc(sizeof(int) * a.len);
	b.pile = (int*)malloc(sizeof(int) * a.len);
	b.len = 0;
	argc = 0;
	nbop = 0;
	while ((++argc - nbop) <= a.len)
		if (ft_strisdigit(argv[argc]))
			a.pile[a.len - (argc - nbop)] = ft_atoi(argv[argc]);
		else
			nbop++;
	if (!verif_doublon(a) || !test_bon(a))
		return (error_msg((!test_bon(a)) ? "Already done\n" : "Error\n"));
	nbop = 0;
	i.a = &a;
	i.b = &b;
	i.p = &p;
	i.nbop = &nbop;
	if (verif_dec(*(i.a)) && i.a->len > 4)
		decroissant(&i);
	else if (a.len < 35)
		croissant(&i);
	else
		tri_a(&i, 0, i.a->len - 1);
	if (p.nbop)
		ft_printf("\noperation effectue : %d", nbop);
	if (p.finalpile)
		affiche_pile(a);
	return (0);
}
