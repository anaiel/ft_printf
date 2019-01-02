/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:29:47 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/08 18:45:34 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (++i < len2)
	{
		s1[len1 + i] = s2[i];
	}
	s1[len1 + len2] = '\0';
	return (s1);
}
