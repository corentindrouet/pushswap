/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:19:32 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/16 08:49:27 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char **argv)
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
		tab[argc] = ft_atoi(argv[argc + 1]);
	return (0);
}
