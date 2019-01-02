/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:23:45 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/06 12:23:46 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		base_len(unsigned long long int n, int base)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char		convert_letter(int n)
{
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (n + 48);
}

char			*ft_itoa_base(unsigned long long int n, int base)
{
	int		i;
	char	*res;

	if (n == -0)
		return (ft_strdup("0"));
	if (!(res = ft_strnew(base_len(n, base))))
		return (NULL);
	i = base_len(n, base);
	res[i--] = 0;
	while (n > 0)
	{
		res[i] = convert_letter(n % base);
		n /= base;
		i--;
	}
	return (res);
}
