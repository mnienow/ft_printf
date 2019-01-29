/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:02:33 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/29 17:12:27 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	main(void)
{
	printf("%d\n", ft_printf("WTF%d WT%c2 %s\n", 1, 'F', "WTF3" ));
	printf("%d", printf("WTF%d WT%c2 %s\n", 1, 'F', NULL));
	//printf("%zu", ft_strlen("WTF1 2WTF2\n"));
	return (0);
}
