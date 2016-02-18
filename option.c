/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:59:59 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/18 11:26:49 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	init_option(int nb, char **argv, t_option *op, int *len)
{
	op->color = 0;
	op->nbop = 0;
	op->finalpile = 0;
	op->etape = 0;
	while (--nb > 0)
	{
		if (!ft_strisdigit(argv[nb]))
		{
			if (!ft_strcmp(argv[nb], "-c"))
				op->color++;
			else if (!ft_strcmp(argv[nb], "-v"))
				op->etape++;
			else if (!ft_strcmp(argv[nb], "-f"))
				op->finalpile++;
			else if (!ft_strcmp(argv[nb], "-o"))
				op->nbop++;
			else
				return (0);
		}
		else
		{
			if (ft_atol(argv[nb]) > 2147483647 || ft_atol(argv[nb]) < -2147483648)
				return (0);
			else
				(*len)++;
		}
	}
	return (1);
}
