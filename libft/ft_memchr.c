/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:39:44 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/14 12:29:28 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*tmp;

	i = -1;
	tmp = (unsigned char *)s;
	while (++i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((void *)(s + i));
	}
	return (NULL);
}
