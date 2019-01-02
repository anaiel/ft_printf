/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubletoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:03:43 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/23 19:03:45 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_doubletoa(double d, int accuracy)
{
	char	*str;
	char	*ret;
	int		i;
	int		temp;

	if (!(str = ft_itoa((int)d)))
		return (NULL);
	if (accuracy == 0)
		return (str);
	i = ft_strlen(str);
	if (!(ret = ft_strnew(i + accuracy + 2)))
		return (NULL);
	ft_strncpy(ret, str, i);
	ret[i] = '.';
	free(str);
	temp = (int)d;
	d -= (float)temp;
	d = (d < 0 ? -d : d);
	d *= ft_power(10, accuracy);
	if (!(str = ft_itoa((int)d)))
		return (NULL);
	ft_strncat(ret, str, accuracy);
	free(str);
	return (ret);
}
