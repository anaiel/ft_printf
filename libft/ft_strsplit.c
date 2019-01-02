/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:17:43 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/18 10:47:26 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	ft_countinstr_noconsecbis(char *s, char c)
{
	unsigned int	cnt;

	if (!*s)
		return (0);
	cnt = 0;
	if (*s != c)
		++cnt;
	while (*++s)
		if (*s == c && *(s - 1) != c)
			cnt++;
	return (cnt);
}

static int			ft_parts(const char *s, char c)
{
	int		cp;
	int		in;

	in = 0;
	cp = 0;
	while (*s)
	{
		if (in == 1 && *s == c)
			in = 0;
		if (in == 0 && *s != c)
		{
			in = 1;
			cp++;
		}
		s++;
	}
	return (cp);
}

static int			ft_len(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_wrd;
	int		i;

	if (!s || !c)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) *
					(ft_countinstr_noconsecbis((char *)s, c) + 1))))
		return (NULL);
	i = 0;
	nb_wrd = ft_parts((const char *)s, c);
	while (nb_wrd--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_len((const char *)s, c));
		if (tab[i++] == NULL)
			return (NULL);
		s += ft_len(s, c);
	}
	tab[i] = NULL;
	return (tab);
}
