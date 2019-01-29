/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:29:34 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/12 19:38:13 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static void	jfree(void *cont, size_t size)
{
	size = 0;
	free(cont);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst2;
	t_list *lst3;

	if (!lst && !f)
		return (NULL);
	lst2 = f(lst);
	lst3 = lst2;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst2->next = f(lst)))
		{
			ft_lstdel(&lst3, jfree);
			return (NULL);
		}
		lst2 = lst2->next;
	}
	return (lst3);
}
