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
	printf("%d\n", ft_printf("WTF%d WT%c 2 %5% %s\n WTF4%c\n", 1, '\0', NULL, 'a'));
	printf("\n");
	printf("%d\n",    printf("WTF%d WT%c 2 %5% %s\n WTF4%c\n", 1, '\0', NULL, 'a'));
	// printf("%d\n", ft_printf("WTF%d WT%c 2 %5% %s\n WTF%c4\n %x", 1, '\0', NULL, '\0', 987654321));
	// printf("\n");
	// printf("%d\n",    printf("WTF%d WT%c 2 %5% %s\n WTF%c4\n %x", 1, '\0', NULL, '\0', 987654321));
	// printf("\n");
	// printf("\n");
 	// ft_printf("%s\n", NULL);
	// printf("\n");
	// printf("%s\n", NULL);
	return (0);
}
//" 2 12345% (null)\n WTF4a\n"
