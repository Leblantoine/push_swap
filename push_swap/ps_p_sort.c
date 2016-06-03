/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:58:58 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 13:22:59 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pa_sort(t_all *all)
{
	if (all->b->len > 0)
	{
		all->a->pile[all->a->len] = all->b->pile[all->b->len - 1];
		all->b->pile[all->b->len - 1] = 0;
		all->a->len++;
		all->b->len--;
		if (all->opc == 1)
			ft_putstr("\033[0;36m");
		if (all->op == 0 || all->opv == 1)
			write(1, "pa", 2);
		else
			write(1, " pa", 3);
		if (all->opc == 1)
			ft_putstr("\033[0m");
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}

int		pb_sort(t_all *all)
{
	if (all->a->len > 0)
	{
		all->b->pile[all->b->len] = all->a->pile[all->a->len - 1];
		all->a->pile[all->a->len - 1] = 0;
		all->b->len++;
		all->a->len--;
		if (all->opc == 1)
			ft_putstr("\033[0;32m");
		if (all->op == 0 || all->opv == 1)
			write(1, "pb", 2);
		else
			write(1, " pb", 3);
		if (all->opc == 1)
			ft_putstr("\033[0m");
		all->op++;
		if (all->opv == 1)
			show_pile(all);
		return (1);
	}
	return (0);
}
