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
#include <limits.h>

int	main(void)
{
	int a;
	int *b;

	b = &a;
	printf("Original\n");
	printf("\n%d\n", printf("%70.15f", 0.0000001));
	printf("------------------------------\n");
	printf("Our\n");
	printf("\n%d\n", ft_printf("%70.15f", 0.0000001));
	printf("------------------------------\n");
	printf("Original\n");
	printf("\n%d\n", printf("%.f", 0.0));
	printf("------------------------------\n");
	printf("Our\n");
	printf("\n%d\n", ft_printf("%.f", 0.0));
	printf("------------------------------\n");
	return (0);
}