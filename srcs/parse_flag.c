/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:28:38 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/05/06 16:28:11 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	*initialise_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag) * 5);
	flag[0].c = ' ';
	flag[1].c = '#';
	flag[2].c = '+';
	flag[3].c = '0';
	flag[4].c = '-';
	flag[0].f = &flag_space;
	flag[1].f = &flag_hash;
	flag[2].f = &flag_plus;
	flag[3].f = &flag_zero;
	flag[4].f = &flag_minus;
	return (flag);
}

static char		*specs_ignore(char *specs)
{
	int		i;

	i = -1;
	if (ft_strchr("diouxX", specs[ft_strlen(specs) - 1])
			&& ft_strchr(specs, '.'))
		while (specs[++i])
			if (specs[i] == '0')
				specs[i] = '%';
	if (ft_strchr(specs, '-'))
		while (specs[++i])
			if (specs[i] == '0')
				specs[i] = '%';
	i = -1;
	if (ft_strchr(specs, '+'))
		while (specs[++i])
			if (specs[i] == ' ')
				specs[i] = '%';
	return (specs);
}

char			*parse_flag(char *str, char *specs)
{
	int		i;
	t_flag	*flag;

	flag = initialise_flag();
	specs = specs_ignore(specs);
	i = 0;
	while (i < 5)
	{
		if (ft_strchr(specs, flag[i].c))
			str = flag[i].f(str, specs[ft_strlen(specs) - 1]);
		i++;
	}
	free(flag);
	return (str);
}
