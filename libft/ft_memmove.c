/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:19:46 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/14 17:36:32 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*str;

	str = dst;
	if (dst < src)
		while ((size_t)(dst - str) < len)
			*(char *)dst++ = *(char *)src++;
	else
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	return (str);
}
