/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:52:54 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/18 10:37:51 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*res;

	if (lst && f)
	{
		res = f(lst);
		if (res && lst->next)
			res->next = ft_lstmap(lst->next, f);
		return (res);
	}
	return (NULL);
}
