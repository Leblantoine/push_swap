/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 07:49:03 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 17:15:58 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*init_b(int len)
{
	t_pile		*b;

	if (!(b = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	if (!(b->pile = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	b->len = 0;
	return (b);
}

t_all		*init_check_option(char **tab)
{
	t_all	*all;
	int		i;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	all->op = 0;
	all->opv = 0;
	all->ops = 0;
	all->opo = 0;
	all->opc = 0;
	all->ope = 0;
	i = 0;
	while (tab[++i])
		if (ft_strcmp(tab[i], "-v") == 0)
			all->opv = 1;
		else if (ft_strcmp(tab[i], "-s") == 0)
			all->ops = 1;
		else if (ft_strcmp(tab[i], "-e") == 0)
			all->ope = 1;
		else if (ft_strcmp(tab[i], "-c") == 0)
			all->opc = 1;
		else if (ft_strcmp(tab[i], "-o") == 0)
			all->opo = 1;
	return (all);
}

void		put_state(t_all *all, int where)
{
	if (where == 1 && all->ops == 1)
	{
		ft_putstr("Start state :");
		show_pile(all);
	}
	if (where == 2 && all->ope == 1)
	{
		ft_putstr("Final state :");
		show_pile(all);
	}
}

int			main(int argc, char **argv)
{
	t_all		*all;

	if (argc > 1)
	{
		if (!(all = init_check_option(argv)))
			return (error_return());
		if ((all->a = check_stock(argv)) == NULL)
			return (error_return());
		if (LENA <= 0)
			return (error_return());
		if ((all->b = init_b(all->a->len + 1)) == NULL)
			return (error_return());
		put_state(all, 1);
		sort(all);
		put_state(all, 2);
		if (all->opo == 1)
			ft_printf("Operation : %d\n", all->op);
	}
	else
		return (error_return());
	return (0);
}
