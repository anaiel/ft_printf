/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions_binary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:53:33 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/05/06 16:24:13 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*bytes_to_string(long int x)
{
	char		*str;
	long int	z;

	if (x > 2147483647 || x < -2147483648)
	{
		if (!(str = ft_strnew(65)))
			return (NULL);
		z = 4611686018427387904;
	}
	else
	{
		if (!(str = ft_strnew(33)))
			return (NULL);
		z = 1073741824;
	}
	if (x >= 0)
		str[0] = '0';
	else
		str[0] = '1';
	while (z > 0)
	{
		ft_strcat(str, ((x & z) ? "1" : "0"));
		z >>= 1;
	}
	return (str);
}

char		*conv_binary(va_list ap, char *mod)
{
	char	*res;

	mod += 0;
	if (!(res = ft_strdup(bytes_to_string(va_arg(ap, long int)))))
		exit_error("error: malloc failed\n", 0);
	return (res);
}
