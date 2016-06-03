/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insert_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:34:01 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 08:31:58 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			where_a_in_b(t_all *all)
{
	int		i;
	int		u;
	int		max;

	i = -1;
	u = -2147483648;
	max = -2147483648;
	while (++i < LENB)
	{
		if (all->b->pile[i] < TOPA && u < all->b->pile[i])
			u = all->b->pile[i];
		if (max < all->b->pile[i])
			max = all->b->pile[i];
	}
	if (u == -2147483648)
		u = max;
	return (u);
}

int			get_max(t_pile *b)
{
	int		i;
	int		u;

	i = -1;
	u = -2147483648;
	while (++i < b->len)
	{
		if (u < b->pile[i])
			u = b->pile[i];
	}
	return (u);
}

int			get_index(t_pile *b, int nb)
{
	int		i;

	i = 0;
	while (b->pile[i] != nb)
		i++;
	return (i);
}

void		insert_sort(t_all *all)
{
	int		i;

	pb_sort(all);
	while (LENA > 0)
	{
		i = where_a_in_b(all);
		if (get_index(all->b, i) >= (LENB - 1) / 2)
			while (TOPB != i)
				rb_sort(all);
		else
			while (TOPB != i)
				rrb_sort(all);
		pb_sort(all);
	}
	i = get_max(all->b);
	if (get_index(all->b, i) >= (LENB - 1) / 2)
		while (TOPB != i)
			rb_sort(all);
	else
		while (TOPB != i)
			rrb_sort(all);
	while (LENB > 0)
		pa_sort(all);
}
