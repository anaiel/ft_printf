/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:49:49 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/14 14:09:57 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ndllen;

	if (!(*needle))
		return ((char *)haystack);
	ndllen = ft_strlen(needle);
	while (*haystack && len-- >= ndllen)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, ndllen) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
