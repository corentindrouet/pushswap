/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:48:35 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/16 10:57:19 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include "libft/libft.h"

void	croissant(int *tab, int *nbr);
void	swap_a(int *tab, int taille);
void	push_a(int *tab1, int *t1, int *tab2, int *t2);
void	rotate_a(int *tab1, int taille);
void	reverse_rotate_a(int *tab1, int taille);
void	swap_b(int *tab, int taille);
void	push_b(int *tab1, int *t1, int *tab2, int *t2);
void	rotate_b(int *tab1, int taille);
void	reverse_rotate_b(int *tab1, int taille);

#endif
