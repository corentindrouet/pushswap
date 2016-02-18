/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:19:32 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/18 11:47:32 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	trace(t_pile a, t_pile b, t_option p)
{
	if (p.color)
		ft_printf("{rouge}");
	ft_printf("\npile_a : ");
	while (--a.len >= 0)
		ft_printf("%d ", a.pile[a.len]);
	if (p.color)
		ft_printf("{eoc}");
	ft_printf("\n");
	if (p.color)
		ft_printf("{cyan}");
	ft_printf("pile_b : ");
	while (--b.len >= 0)
		ft_printf("%d ", b.pile[b.len]);
	if (p.color)
		ft_printf("{eoc}");
	ft_printf("\n\n");
}

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

int 	croissant(t_pile *a, t_pile *b, int	*nbop, t_option p)
{
	if (b->len == 0 && !test_bon(*a))
		return (1);
	if (a->len >= 2 && (a->pile[a->len - 1] > a->pile[a->len - 2]))
	{
		if (a->pile[a->len - 1] == max_tab(*a))
			rotate_a(a, p);
		else
			swap_a(a, p);
		(*nbop)++;
		if (p.etape)
			trace(*a, *b, p);
	}
	if (b->len >= 2 && b->pile[b->len - 1] < b->pile[b->len - 2])
	{
		if (b->pile[b->len - 1] == min_tab(*b))
			rotate_b(b, p);
		else
			swap_b(b, p);
		(*nbop)++;
		if (p.etape)
			trace(*a, *b, p);
	}
	if (a->len > 2 && a->pile[0] == min_tab(*a))
	{
		reverse_rotate_a(a, p);
		(*nbop)++;
		if (p.etape)
			trace(*a, *b, p);
	}
	if (b->len > 2 && b->pile[0] == max_tab(*b))
	{
		reverse_rotate_b(b, p);
		(*nbop)++;
		if (p.etape)
			trace(*a, *b, p);
	}
	if (!test_bon(*a) && b->len != 0)
		push_a(a, b, p);
	else
		push_b(b, a, p);
	(*nbop)++;
	if (p.etape)
		trace(*a, *b, p);
	croissant(a, b, nbop, p);
	return (1);
}

int		main(int argc, char **argv)
{
	t_pile		a;
	t_pile		b;
	t_option	p;
	int			nbop;

	if (argc == 1)
		return (0);
	a.len = 0;
	if (!init_option(argc, argv, &p, &(a.len)))
		ft_printf("Error\n");
	a.pile = (int*)malloc(sizeof(int) * a.len);
	b.pile = (int*)malloc(sizeof(int) * a.len);
	b.len = 0;
	argc = -1;
	while (++argc < a.len)
		a.pile[a.len - argc - 1] = ft_atoi(argv[argc + 1]);
	nbop = 0;
	croissant(&a, &b, &nbop, p);
	argc = 0;
	if (p.nbop)
		ft_printf("\noperation effectue : %d", nbop);
	if (p.finalpile)
	{
		ft_printf("\npile finale : ");
		while (argc < a.len)
			ft_printf("%d ", a.pile[argc++]);
	}
	return (0);
}
