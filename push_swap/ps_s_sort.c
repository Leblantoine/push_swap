/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_s_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:58:58 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 13:37:19 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa_sort(t_all *all)
{
	int		tmp;

	if (all->a->len >= 2)
	{
		tmp = all->a->pile[all->a->len - 1];
		all->a->pile[all->a->len - 1] = all->a->pile[all->a->len - 2];
		all->a->pile[all->a->len - 2] = tmp;
		if (all->opc == 1)
			ft_putstr("\033[0;36m");
		if (all->op == 0 || all->opv == 1)
			write(1, "sa", 2);
		else
			write(1, " sa", 3);
		if (all->opc == 1)
			ft_putstr("\033[0m");
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}

int		sb_sort(t_all *all)
{
	int		tmp;

	if (all->b->len >= 2)
	{
		tmp = all->b->pile[all->b->len - 1];
		all->b->pile[all->b->len - 1] = all->b->pile[all->b->len - 2];
		all->b->pile[all->b->len - 2] = tmp;
		if (all->opc == 1)
			ft_putstr("\033[0;32m");
		if (all->op == 0 || all->opv == 1)
			write(1, "sb", 2);
		else
			write(1, " sb", 3);
		if (all->opc == 1)
			ft_putstr("\033[0m");
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}

int		ss_sort(t_all *all)
{
	int		tmp;

	if (all->a->len >= 2 && all->b->len >= 2)
	{
		tmp = all->a->pile[all->a->len - 1];
		all->a->pile[all->a->len - 1] = all->a->pile[all->a->len - 2];
		all->a->pile[all->a->len - 2] = tmp;
		tmp = all->b->pile[all->b->len - 1];
		all->b->pile[all->b->len - 1] = all->b->pile[all->b->len - 2];
		all->b->pile[all->b->len - 2] = tmp;
		if (all->op == 0 || all->opv == 1)
			write(1, "ss", 2);
		else
			write(1, " ss", 3);
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}
