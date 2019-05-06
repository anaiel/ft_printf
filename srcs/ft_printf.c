/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:47:15 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/05/06 16:27:53 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*converter(char *specs, va_list ap)
{
	char	*res;
	char	*res_nullchar;
	int		i;

	if (specs[ft_strlen(specs) - 1] == 'i')
		specs[ft_strlen(specs) - 1] = 'd';
	if (!specs[0]
			|| ft_strchr(" .lhzj+-0123456789#L", specs[ft_strlen(specs) - 1]))
		return (ft_strdup(""));
	res = parse_conv(ap, specs);
	res = parse_accufield(res, specs);
	res = parse_flag(res, specs);
	if (specs[ft_strlen(specs) - 1] == 'c' && ft_strstr(res, "^@"))
	{
		write(1, res, 1);
		if (!(res_nullchar = ft_strdup(res + 1)))
			exit_error("error: malloc failed\n", 2, res, specs);
		free(res);
		return (res_nullchar);
	}
	if (ft_strchr("dfi", specs[ft_strlen(specs) - 1]) && (i = -1))
		while (res[++i])
			if (res[i] == '\t')
				res[i] = ' ';
	return (res);
}

static t_form	init_struct(const char *format)
{
	t_form	anc;

	anc.i = 0;
	anc.cnt = 0;
	anc.fmt = format;
	return (anc);
}

static t_form	write_color(t_form anc)
{
	char *color;

	if ((color = parse_color(anc.fmt + anc.i)))
	{
		write(1, anc.fmt, anc.i);
		anc.cnt += anc.i;
		if (!ft_strequ(color, "\033[0m"))
			write(1, color, 7);
		else
			write(1, color, 4);
		anc.fmt += param_len(anc.fmt + anc.i) + anc.i;
		anc.i = 0;
	}
	else
		anc.i++;
	return (anc);
}

static t_form	write_arg(t_form anc, va_list ap)
{
	char	*specs;
	char	*arg;

	write(1, anc.fmt, anc.i);
	anc.cnt += anc.i;
	anc.fmt += anc.i + 1;
	anc.i = 0;
	while (anc.fmt[anc.i] && (ft_strchr(" #+-.jhlzL", anc.fmt[anc.i])
			|| (anc.fmt[anc.i] >= '0' && anc.fmt[anc.i] <= '9')))
		anc.i++;
	specs = ft_strsub(anc.fmt, 0, anc.i + 1);
	arg = converter(specs, ap);
	write(1, arg, ft_strlen(arg));
	if (anc.fmt[0] &&
			ft_strchr(" .0123456789#+-jzhlL", *(anc.fmt + anc.i)))
		anc.fmt += anc.i;
	else if (anc.fmt[0])
		anc.fmt += anc.i + 1;
	anc.cnt += ft_strlen(arg);
	free(specs);
	free(arg);
	anc.i = 0;
	return (anc);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_form		anc;

	va_start(ap, format);
	anc = init_struct(format);
	while (anc.fmt[anc.i])
	{
		if (anc.fmt[anc.i] == '{')
			anc = write_color(anc);
		else if (anc.fmt[anc.i] == '%')
			anc = write_arg(anc, ap);
		else
			anc.i++;
	}
	write(1, anc.fmt, ft_strlen(anc.fmt));
	anc.cnt += ft_strlen(anc.fmt);
	va_end(ap);
	return (anc.cnt);
}
