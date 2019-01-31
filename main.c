/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:02:33 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/29 18:53:24 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	main(void)
{
	//ft_printf("WTF%d WT%c2 %s\n WTF%c4\n", 1, '\0', "3", '\0');
	printf("%d\n", ft_printf("WTF%d WT%c2 %s\n WTF%c4\n", 1, '\0', "3", '\0'));
	printf("%d\n",    printf("WTF%d WT%c2 %s\n WTF%c4\n", 1, '\0', "3", '\0'));
	//ft_printf("WTF1 WT\0\2 WTF3");
	//printf("\n");
	//printf("WTF1 WT\0\2 WTF3");
	//printf("%zu", ft_strlen("WTF1 2WTF2\n"));
	return (0);
}