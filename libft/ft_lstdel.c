/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:18:46 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/06 22:24:31 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst && *alst && del)
	{
		while ((*alst))
		{
			tmp = (*alst);
			tmp = tmp->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = 0;
			(*alst) = tmp;
		}
	}
}
