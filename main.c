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
#include <stdio.h>

int	main(void)
{
	int a;
	int *b;

	b = &a;
	printf("------------------------------\n");
	printf("Original\n");
	printf("(%d)\n", printf("@moulitest: %#.x %#.0x", 0, 0));
	printf("Our\n");
	printf("(%d)\n", ft_printf("@moulitest: %#.x %#.0x", 0, 0));
	printf("------------------------------\n");
	printf("Original\n");
	printf("(%d)\n", printf("%03.2d", 0));
	printf("Our\n");
	printf("(%d)\n", ft_printf("%03.2d", 0));
	printf("------------------------------\n");
	printf("Original\n");
	printf("(%d)\n", printf("@moulitest: %5.d %5.0d", 0, 0));
	printf("Our\n");
	printf("(%d)\n", ft_printf("@moulitest: %5.d %5.0d", 0, 0));
	printf("------------------------------");
	return (0);
}
