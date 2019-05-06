/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:54:00 by anleclab          #+#    #+#             */
/*   Updated: 2019/05/06 16:28:19 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				move_right(char *str, int nbchar, char c)
{
	int		i;

	i = ft_strlen(str) - nbchar;
	while (str[i] == ' ')
		i++;
	if (str[i])
		return (0);
	i = ft_strlen(str) - 1;
	while (i - nbchar >= 0)
	{
		str[i] = str[i - nbchar];
		i--;
	}
	while (i >= 0)
	{
		str[i] = c;
		i--;
	}
	return (1);
}

static char		*suffix_ret(char *suf, char *str, int init_sp, int end_sp)
{
	int		tmp;
	int		i;
	char	*ret;

	tmp = ft_strlen(str);
	if (!(ret = ft_strnew(tmp + ft_strlen(suf) - init_sp - end_sp)))
		exit_error("error: malloc failed\n", 1, str);
	ft_strncpy(ret, suf, ft_strlen(suf));
	ret = ft_strncat(ret, str + init_sp, ft_strlen(str) - init_sp - end_sp);
	free(str);
	if (!(str = ft_strnew(tmp)))
		exit_error("error: malloc failed\n", 1, str);
	i = 0;
	if (ft_strlen(suf) == 2)
		init_sp--;
	while (i < init_sp - 1)
	{
		str[i] = ' ';
		i++;
	}
	str = ft_strcat(str, ret);
	free(ret);
	return (str);
}

static char		*suffix_condition(char *suf, char *str, int init_sp, int end_sp)
{
	int		i;

	if (init_sp + end_sp >= (int)ft_strlen(suf))
	{
		i = ft_strlen(suf) - 1;
		while (--init_sp >= 0 && i >= 0)
		{
			str[init_sp] = suf[i];
			i--;
		}
		if (i >= 0)
		{
			move_right(str, i + 1, '0');
			while (i >= 0)
			{
				str[i] = suf[i];
				i--;
			}
		}
		return (str);
	}
	return (NULL);
}

char			*suffix(char *suf, char *str)
{
	int		init_sp;
	int		end_sp;

	init_sp = 0;
	while (str[init_sp] == ' ')
		init_sp++;
	end_sp = 0;
	while (str[ft_strlen(str) - 1 - end_sp] == ' ')
		end_sp++;
	if (suffix_condition(suf, str, init_sp, end_sp))
		str = suffix_condition(suf, str, init_sp, end_sp);
	return (suffix_ret(suf, str, init_sp, end_sp));
}

unsigned char	*concatenate(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*res;
	int				len1;
	int				len2;
	int				i;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!(res = (unsigned char *)ft_strnew(len1 + len2 + 1)))
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	i = -1;
	while (++i < len2)
		res[len1 + i] = s2[i];
	free(s1);
	free(s2);
	return (res);
}
