/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:02:33 by mnienow           #+#    #+#             */
/*   Updated: 2019/02/01 16:46:00 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	main(void)
{
	// printf("(%d)\n", ft_printf("WTF%d WT%c 2 %s\n WTF4%4c\n WTF5%c\n", 1, '\0', NULL, 'a', 'b'));
	// printf("\n");
	// printf("(%d)\n",    printf("WTF%d WT%c 2 %s\n WTF4%4c\n WTF5%c\n", 1, '\0', NULL, 'a', 'b'));
	printf("(%d)\n", ft_printf("% d", -42));
	printf("\n");
	printf("(%d)\n",    printf("% d", -42));

	return (0);
}