/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:58:58 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 13:28:16 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ra_sort(t_all *all)
{
	int		i;
	int		tmp;

	if (all->a->len > 1)
	{
		i = all->a->len;
		tmp = all->a->pile[all->a->len - 1];
		while (--i > 0)
			all->a->pile[i] = all->a->pile[i - 1];
		all->a->pile[0] = tmp;
		if (all->opc == 1)
			ft_putstr("\033[0;36m");
		if (all->op == 0 || all->opv == 1)
			write(1, "ra", 2);
		else
			write(1, " ra", 3);
		if (all->opc == 1)
			ft_putstr("\033[0m");
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}

int		rb_sort(t_all *all)
{
	int		i;
	int		tmp;

	if (all->b->len > 1)
	{
		i = all->b->len;
		tmp = all->b->pile[all->b->len - 1];
		while (--i > 0)
			all->b->pile[i] = all->b->pile[i - 1];
		all->b->pile[0] = tmp;
		if (all->opc == 1)
			ft_putstr("\033[0;32m");
		if (all->op == 0 || all->opv == 1)
			write(1, "rb", 2);
		else
			write(1, " rb", 3);
		if (all->opc == 1)
			ft_putstr("\033[0m");
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}

int		rr_sort(t_all *all)
{
	int		i;
	int		tmp;

	if (all->a->len > 1 && all->b->len > 1)
	{
		i = all->a->len;
		tmp = all->a->pile[all->a->len - 1];
		while (--i > 0)
			all->a->pile[i] = all->a->pile[i - 1];
		all->a->pile[0] = tmp;
		i = all->b->len;
		tmp = all->b->pile[all->b->len - 1];
		while (--i > 0)
			all->b->pile[i] = all->b->pile[i - 1];
		all->b->pile[0] = tmp;
		if (all->op == 0 || all->opv == 1)
			write(1, "rr", 2);
		else
			write(1, " rr", 3);
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}
