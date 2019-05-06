/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:57:10 by anleclab          #+#    #+#             */
/*   Updated: 2019/05/06 16:26:37 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_d(va_list ap, char *mod)
{
	long long int	res;

	res = 0;
	if (ft_strequ(mod, "l"))
		return (ft_litoa(va_arg(ap, long)));
	else if (ft_strequ(mod, "ll"))
		return (ft_llitoa(va_arg(ap, long long)));
	else if (ft_strequ(mod, "h"))
		res = (short int)va_arg(ap, int);
	else if (ft_strequ(mod, "hh"))
		res = (char)va_arg(ap, int);
	else if (ft_strequ(mod, "j"))
		return (ft_llitoa(va_arg(ap, intmax_t)));
	else if (ft_strequ(mod, "z"))
		return (ft_llitoa(va_arg(ap, ssize_t)));
	else if (*mod == 0)
		res = va_arg(ap, int);
	return (ft_itoa(res));
}

char	*conv_o(va_list ap, char *mod)
{
	unsigned long long int	res;

	res = 0;
	if (ft_strequ(mod, "l"))
		res = va_arg(ap, unsigned long);
	else if (ft_strequ(mod, "ll"))
		res = va_arg(ap, unsigned long long);
	else if (ft_strequ(mod, "h"))
		res = va_arg(ap, unsigned int) & 0xFFFF;
	else if (ft_strequ(mod, "hh"))
		res = va_arg(ap, unsigned int) & 0xFF;
	else if (ft_strequ(mod, "j"))
		res = va_arg(ap, uintmax_t);
	else if (ft_strequ(mod, "z"))
		res = va_arg(ap, size_t);
	else if (*mod == 0)
		res = va_arg(ap, unsigned int);
	if (res == 0)
		return (ft_strdup("0"));
	return (ft_itoa_base(res, 8));
}

char	*conv_u(va_list ap, char *mod)
{
	long long int	res;

	res = 0;
	if (ft_strequ(mod, "l"))
		res = va_arg(ap, unsigned long);
	else if (ft_strequ(mod, "ll"))
		res = va_arg(ap, unsigned long long);
	else if (ft_strequ(mod, "h"))
		res = va_arg(ap, unsigned int) & 0xFFFF;
	else if (ft_strequ(mod, "hh"))
		res = va_arg(ap, unsigned int) & 0xFF;
	else if (ft_strequ(mod, "j"))
		res = va_arg(ap, uintmax_t);
	else if (ft_strequ(mod, "z"))
		res = va_arg(ap, size_t);
	else if (*mod == 0)
		res = va_arg(ap, unsigned int);
	return (ft_itoa_base(res, 10));
}

char	*conv_x(va_list ap, char *mod)
{
	long long int	res;

	res = 0;
	if (ft_strequ(mod, "l"))
		res = va_arg(ap, unsigned long);
	else if (ft_strequ(mod, "ll"))
		res = va_arg(ap, unsigned long long);
	else if (ft_strequ(mod, "h"))
		res = va_arg(ap, unsigned int) & 0xFFFF;
	else if (ft_strequ(mod, "hh"))
		res = va_arg(ap, unsigned int) & 0xFF;
	else if (ft_strequ(mod, "j"))
		res = va_arg(ap, uintmax_t);
	else if (ft_strequ(mod, "z"))
		res = va_arg(ap, size_t);
	else if (*mod == 0)
		res = va_arg(ap, unsigned int);
	return (ft_itoa_base(res, 16));
}

char	*conv_big_x(va_list ap, char *mod)
{
	int		i;
	char	*res;

	i = -1;
	res = conv_x(ap, mod);
	while (res[++i])
		res[i] = ft_toupper(res[i]);
	return (res);
}
