/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:58:58 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 13:37:07 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra_sort(t_all *all)
{
	int		i;
	int		tmp;

	if (all->a->len > 1)
	{
		i = -1;
		tmp = all->a->pile[0];
		while (++i < all->a->len - 1)
			all->a->pile[i] = all->a->pile[i + 1];
		all->a->pile[all->a->len - 1] = tmp;
		if (all->opc == 1)
			ft_putstr("\033[0;36m");
		if (all->op == 0 || all->opv == 1)
			write(1, "rra", 3);
		else
			write(1, " rra", 4);
		if (all->opc == 1)
			ft_putstr("\033[0m");
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}

int		rrb_sort(t_all *all)
{
	int		i;
	int		tmp;

	if (all->b->len > 1)
	{
		i = -1;
		tmp = all->b->pile[0];
		while (++i < all->b->len - 1)
			all->b->pile[i] = all->b->pile[i + 1];
		all->b->pile[all->b->len - 1] = tmp;
		if (all->opc == 1)
			ft_putstr("\033[0;32m");
		if (all->op == 0 || all->opv == 1)
			write(1, "rrb", 3);
		else
			write(1, " rrb", 4);
		if (all->opc == 1)
			ft_putstr("\033[0m");
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}

int		rrr_sort(t_all *all)
{
	int		i;
	int		tmp;

	if (all->b->len > 1)
	{
		i = -1;
		tmp = all->a->pile[0];
		while (++i < all->a->len - 1)
			all->a->pile[i] = all->a->pile[i + 1];
		all->a->pile[all->a->len - 1] = tmp;
		i = -1;
		tmp = all->b->pile[0];
		while (++i < all->b->len - 1)
			all->b->pile[i] = all->b->pile[i + 1];
		all->b->pile[all->b->len - 1] = tmp;
		if (all->op == 0)
			write(1, "rrr", 3 || all->opv == 1);
		else
			write(1, " rrr", 4);
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}
