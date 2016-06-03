/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:08:04 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 17:07:47 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		*free_return(void *fr, void *re)
{
	free(fr);
	return (re);
}

int			error_return(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

void		show_pile(t_all *all)
{
	int		i;

	i = -1;
	ft_putstr("\nPile a : ");
	while (++i < all->a->len)
	{
		ft_putnbr(all->a->pile[i]);
		write(1, " ", 1);
	}
	i = -1;
	ft_putstr("\nPile b : ");
	while (++i < all->b->len)
	{
		ft_putnbr(all->b->pile[i]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}
