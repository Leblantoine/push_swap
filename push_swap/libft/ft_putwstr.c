/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:51:10 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/23 11:52:02 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwstr(wchar_t *wstr)
{
	int		i;

	i = 0;
	while (*wstr)
	{
		i = i + ft_putwchar(*wstr);
		wstr++;
	}
	return (i);
}
