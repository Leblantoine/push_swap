/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 08:42:40 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 16:40:48 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_sort(t_all *all)
{
	rra_sort(all);
	rra_sort(all);
	sa_sort(all);
	ra_sort(all);
	ra_sort(all);
}

int		average(t_pile *a)
{
	int		i;
	int		u;

	i = -1;
	u = 0;
	while (++i < a->len - 1)
		u += a->pile[i];
	u = u / i;
	return (u);
}

int		ave_in_a(t_all *all, int ave)
{
	int		i;

	i = 0;
	while (i < LENA)
	{
		if (all->a->pile[i] <= ave)
			return (1);
		i++;
	}
	return (0);
}

void	little_sort_help(t_all *all)
{
	int		ave;

	ave = average(all->a);
	while (ave_in_a(all, ave) && LENB < 3)
		if (TOPA <= ave)
			pb_sort(all);
		else
			ra_sort(all);
	while (!check_part(all, 0, LENA - 1))
		if (TOPA > average(all->a))
			ra_sort(all);
		else
			sa_sort(all);
	while (!check_allrev(all->b, 0, LENB - 1))
		if (TOPB <= average(all->b))
			rb_sort(all);
		else
			sb_sort(all);
	while (LENB > 0)
	{
		pa_sort(all);
		if (TOPA > all->a->pile[LENA - 2])
			sa_sort(all);
	}
}

int		little_sort(t_all *all)
{
	if (check_part(all, 2, LENA - 1) && all->a->pile[1] >= get_max(all->a)
			&& all->a->pile[0] > all->a->pile[2])
		a_sort(all);
	if (check_part(all, 0, LENA - 3) && !check_part(all, 0, LENA - 1) &&
			all->a->pile[LENA - 2] < all->a->pile[LENA - 3])
		sa_sort(all);
	if (check_part(all, 0, LENA - 1))
		return (0);
	if (LENA < 7)
		little_sort_help(all);
	return (0);
}
