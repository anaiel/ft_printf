/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:46:45 by anleclab          #+#    #+#             */
/*   Updated: 2019/05/06 16:26:42 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*deci_part(long double dbl, int accu)
{
	char		*res;
	int			i;
	long double	tmp;

	if (!(res = ft_strnew(accu + 1)))
		exit_error("error: malloc failed\n", 0);
	i = -1;
	while (++i < accu)
		dbl *= 10;
	i = 0;
	while (--accu >= 0)
	{
		tmp = dbl / ft_double_power(10.0, accu);
		res[i] = '0' + (int)tmp;
		dbl -= (long double)((int)tmp * ft_double_power(10.0, accu));
		i++;
	}
	return (res);
}

static char	*concat(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = ft_strnew(len1 + len2 + 1)))
		exit_error("error: malloc failed\n", 2, s1, s2);
	ft_strncpy(res, s1, len1);
	ft_strncat(res, s2, len2);
	return (res);
}

static char	*integ_part(long double *dbl)
{
	int			pow_max;
	int			i;
	long double	tmp;
	char		*res;

	*dbl = (*dbl < 0 ? -*dbl : *dbl);
	tmp = *dbl;
	pow_max = 0;
	while (tmp > 10.0)
	{
		pow_max++;
		tmp /= 10;
	}
	if (!(res = ft_strnew(pow_max + 1)))
		exit_error("error: malloc failed\n", 0);
	i = 0;
	while (pow_max >= 0)
	{
		tmp = *dbl / ft_ldouble_power(10, pow_max);
		res[i] = '0' + (int)tmp;
		*dbl -= (long double)((int)tmp * ft_ldouble_power(10, pow_max));
		pow_max--;
		i++;
	}
	return (res);
}

static int	get_accuracy(char *specs)
{
	int		res;
	int		i;

	i = 0;
	while (specs[i] && specs[i] != '.')
		i++;
	res = (specs[i] == '.' ? ft_atoi(specs + i + 1) : 6);
	res = (res < 0 ? 0 : res);
	return (res);
}

char		*conv_longf(va_list ap, char *specs)
{
	int			accu;
	char		*res;
	long double	dbl;
	char		*tmp;
	int			isneg;

	accu = get_accuracy(specs);
	dbl = (long double)va_arg(ap, long double);
	isneg = (dbl < 0 ? 1 : 0);
	res = integ_part(&dbl);
	if (accu)
	{
		res = concat(res, ft_strdup("."));
		res = concat(res, deci_part(dbl, accu));
	}
	if (isneg)
	{
		if (!(tmp = ft_strnew(ft_strlen(res) + 2)))
			exit_error("error:malloc failed\n", 1, res);
		tmp[0] = '-';
		ft_strncpy(tmp + 1, res, ft_strlen(res));
		free(res);
		res = tmp;
	}
	return (res);
}
