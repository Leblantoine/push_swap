/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:24:06 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 11:07:04 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_part(t_all *all, int start, int end)
{
	if (start == end)
		return (1);
	while (start < end)
	{
		if (all->a->pile[start] < all->a->pile[start + 1])
			return (0);
		start++;
	}
	return (1);
}

static int		piv_left(t_all *all, int piv)
{
	int		i;

	i = 0;
	while (TOPA != piv)
	{
		ra_sort(all);
		i++;
	}
	ra_sort(all);
	i++;
	return (i);
}

static void		pb_quick_sort(t_all *all, int start, int end, int piv)
{
	int		i;
	int		tmp;

	tmp = start;
	i = 0;
	while (tmp++ <= end)
		if (TOPA < piv)
			pb_sort(all);
		else if (TOPA == piv)
		{
			pb_sort(all);
			rb_sort(all);
		}
		else
		{
			ra_sort(all);
			i++;
		}
	if ((end - start) != (all->a->len + all->b->len - 1))
		while (i-- > 0)
			rra_sort(all);
	rrb_sort(all);
	while (LENB > 0)
		pa_sort(all);
}

static int		get_piv(t_all *all, int piv)
{
	int		i;

	i = -1;
	while (++i < LENA)
		if (all->a->pile[i] == piv)
			return (i);
	return (-1);
}

int				quick_sort(t_all *all, int start, int end)
{
	int		i;
	int		piv;
	int		pivi;

	if (check_part(all, start, end))
		return (1);
	pivi = start + (end - start) / 2;
	piv = all->a->pile[pivi];
	pb_quick_sort(all, start, end, piv);
	pivi = get_piv(all, piv);
	if (!check_part(all, pivi + 1, end))
		quick_sort(all, pivi + 1, end);
	if (check_part(all, start, end))
		return (1);
	i = piv_left(all, piv);
	if (!check_part(all, start + i, end))
		quick_sort(all, start + i, end);
	while (i-- > 0)
		rra_sort(all);
	return (1);
}
