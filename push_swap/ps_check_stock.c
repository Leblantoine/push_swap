/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 08:06:58 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 16:48:29 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 1);
}

int			check_nbr(char *str)
{
	int		i;
	int		u;

	i = 0;
	u = 0;
	if (ft_strcmp(str, "-v") == 0 || ft_strcmp(str, "-s") == 0 ||
			ft_strcmp(str, "-o") == 0 || ft_strcmp(str, "-c") == 0 ||
			ft_strcmp(str, "-e") == 0)
		return (2);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
			u++;
		i++;
	}
	if (u == i && i < 12 && ft_atoill(str) < 2147483648 &&
			ft_atoill(str) > -2147483649)
		return (1);
	else
		return (0);
}

int			check_double(int *pile, int last)
{
	int		i;

	i = 0;
	while (i < last)
	{
		if (pile[i] == pile[last])
			return (0);
		i++;
	}
	return (1);
}

t_pile		*check_stock(char **tab)
{
	t_pile		*a;
	int			i;

	if (!(a = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	if (!(a->pile = (int *)malloc(sizeof(int) * tab_len(tab))))
		return (NULL);
	a->len = tab_len(tab);
	i = 0;
	while (a->len > 0)
	{
		if (check_nbr(tab[a->len]) == 1)
		{
			a->pile[i] = ft_atoi(tab[a->len]);
			if (!(check_double(a->pile, i++)))
				return (free_return(a, NULL));
			a->len--;
		}
		else if (check_nbr(tab[a->len]) == 2)
			a->len--;
		else
			return (free_return(a, NULL));
	}
	a->len = i;
	return (a);
}
