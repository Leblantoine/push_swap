/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:05:41 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/01 13:17:40 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_tab_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			while (s[i] != c)
				i++;
			len++;
		}
		i++;
	}
	return (len);
}

static int		ft_word_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		u;
	int		tab_len;
	char	**tab;

	i = 0;
	u = 0;
	tab = NULL;
	tab_len = ft_tab_len(s, c);
	tab = (char **)malloc(sizeof(char *) * tab_len + 1);
	if (tab != NULL)
	{
		while (i < ft_tab_len(s, c))
		{
			while (s[u] == c)
				u++;
			if (s[u] != '\0')
				tab[i] = ft_strsub(s, u, ft_word_len(&s[u], c));
			u = u + ft_word_len(&s[u], c);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
