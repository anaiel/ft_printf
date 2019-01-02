/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:27:54 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/14 18:09:04 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == 32 || s[start] == '\n' || s[start] == '\t') && s[start])
		start++;
	if (!s[start])
		return (ft_strsub(s, 0, 0));
	while ((s[end] == 32 || s[end] == '\n' || s[end] == '\t') && s[end])
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
