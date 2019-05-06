/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_accufield.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:35:36 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/05/06 16:27:59 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_fieldwidth(char *specs)
{
	int		i;
	int		fieldwidth;

	i = 0;
	fieldwidth = 0;
	while (specs[i] && !fieldwidth)
	{
		if (specs[i] == '.')
		{
			i++;
			while (specs[i] >= '0' && specs[i] <= '9')
				i++;
		}
		else if (specs[i] > '0' && specs[i] <= '9')
			fieldwidth = ft_atoi(specs + i);
		else
			i++;
	}
	return (fieldwidth);
}

static char	*remove_accufield(char *specs)
{
	int		i;

	i = 0;
	while (specs[i])
	{
		if (specs[i] == '.')
		{
			i++;
			while (specs[i] >= '0' && specs[i] <= '9')
				specs[i++] = '%';
		}
		else if (specs[i] > '0' && specs[i] <= '9')
			while (specs[i] >= '0' && specs[i] <= '9')
				specs[i++] = '%';
		else
			i++;
	}
	return (specs);
}

char		*parse_accufield(char *str, char *specs)
{
	int		i;
	char	conv;
	int		len;

	conv = specs[ft_strlen(specs) - 1];
	i = 0;
	len = 0;
	while (specs[i] && specs[i] != '.')
		i++;
	if (specs[i] == '.')
	{
		i++;
		len = ft_atoi(specs + i);
		len = (len < 0 ? 0 : len);
		if (!(str = accuracy(str, (size_t)len, specs)))
			exit_error("error: malloc failed\n", 1, specs);
	}
	len = get_fieldwidth(specs);
	if (len)
		if (!(str = field_width(str, len, conv)))
			exit_error("error: malloc failed\n", 2, str, specs);
	specs = remove_accufield(specs);
	return (str);
}
