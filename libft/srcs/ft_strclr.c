/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:33:20 by anleclab          #+#    #+#             */
/*   Updated: 2019/04/04 09:54:07 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Set all the characters of a string to 0.
*/
void	ft_strclr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		*s = 0;
		s++;
	}
}