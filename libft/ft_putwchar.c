/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:04:02 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/23 19:04:54 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>

static void	ft_putwchar_4bytes(wchar_t c)
{
	unsigned char	byte;

	byte = (((c & 1835008) >> 18) + 240);
	write(1, &byte, 1);
	byte = (((c & 258048) >> 12) + 128);
	write(1, &byte, 1);
	byte = (((c & 4032) >> 6) + 128);
	write(1, &byte, 1);
	byte = ((c & 63) + 128);
	write(1, &byte, 1);
}

static void	ft_putwchar_3bytes(wchar_t c)
{
	unsigned char	byte;

	byte = (((c & 61440) >> 12) + 224);
	write(1, &byte, 1);
	byte = (((c & 4032) >> 6) + 128);
	write(1, &byte, 1);
	byte = ((c & 63) + 128);
	write(1, &byte, 1);
}

static void	ft_putwchar_2bytes(wchar_t c)
{
	unsigned char	byte;

	byte = (((c & 1984) >> 6) + 48);
	write(1, &byte, 1);
	byte = ((c & 63) + 128);
	write(1, &byte, 1);
}

int			ft_putwchar(wchar_t c)
{
	if (c & 2031616)
	{
		ft_putwchar_4bytes(c);
		return (4);
	}
	else if (c & 63488)
	{
		ft_putwchar_3bytes(c);
		return (3);
	}
	else if (c & 1920)
	{
		ft_putwchar_2bytes(c);
		return (2);
	}
	write(1, &c, 1);
	return (1);
}
