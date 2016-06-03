/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 12:36:04 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 16:01:04 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_allrev(t_pile *a, int start, int end)
{
	while (start < end)
	{
		if (a->pile[start] > a->pile[start + 1])
			return (0);
		start++;
	}
	return (1);
}

int		reverse_sort(t_all *all)
{
	while (LENA > 3)
		pb_sort(all);
	ra_sort(all);
	sa_sort(all);
	while (LENB > 0)
	{
		pa_sort(all);
		ra_sort(all);
	}
	if (all->opv == 0 && all->op > 0)
		write(1, "\n", 1);
	return (0);
}

int		sort(t_all *all)
{
	if (!check_part(all, 0, LENA - 1))
	{
		if (LENA == 2)
			sa_sort(all);
		if (check_allrev(all->a, 0, LENA - 1))
			return (reverse_sort(all));
		little_sort(all);
		if (LENA < 55 && !check_part(all, 0, LENA - 1))
			insert_sort(all);
		quick_sort(all, 0, LENA - 1);
	}
	if (all->opv == 0 && all->op > 0)
		write(1, "\n", 1);
	return (0);
}
