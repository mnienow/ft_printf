/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:26:26 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/10 16:26:28 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
#include "libft/includes/libft.h"

static char	*hex_width(char *str, t_mod *zeus)
{
	char	*str_spaces;
	char	*tmp;
	int		width;

	width = zeus->min_width - ft_strlen(str);
	str_spaces = (char *)malloc(sizeof(char) * (width + 1));
	str_spaces[width] = '\0';
	while (--width >= 0)
		str_spaces[width] = ' ';
	tmp = str;
	if (zeus->minus)
		str = ft_strjoin(str, str_spaces);
	else
		str = ft_strjoin(str_spaces, str);
	free(tmp);
	free(str_spaces);
	return (str);
}

static char	*hex_precision(char *str, t_mod *zeus, int	i)
{
	char	*str_zero;
	char	*tmp;
	int		count;

	if (i)
		count = zeus->precision - ft_strlen(str);
	else
		count =  zeus->min_width - ft_strlen(str);
	str_zero = (char *)malloc(sizeof(char) * (count + 1));
	str_zero[count] = '\0';
	while (--count >= 0)
		str_zero[count] = '0';
	// if (zeus->sharp)
	// 	str_zero[1] = 'x';
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

static char	*hex_sharp(char *str, t_mod *zeus)
{
	char	*str_sharp;
	char	*tmp;

    printf("%s\n", str);
	str_sharp = "0x";
	tmp = str;
	str = ft_strjoin(str_sharp, str);
	free(tmp);
	return (str);
}

//void	ft_hex(va_list ap, char **str, t_mod *zeus)
void	ft_pnt(char **str, t_mod *zeus, void *point)
{
	unsigned long int		hex;
	char	*string;

	hex = (unsigned long int)point;
	//hex = va_arg(ap, int);
	printf("(%lu)\n", hex);
	string = ft_itoal(hex, 16, zeus);
	if (zeus->precision)
		string = hex_precision(string, zeus, 1);
	if (1)
		string = hex_sharp(string, zeus);
	if (zeus->zero && !(zeus->precision) && zeus->min_width)
		string = hex_precision(string, zeus, 0);
	if (zeus->min_width > ft_strlen(string))
		string = hex_width(string, zeus);
	*str = ft_strjoin(*str, string);
	free(string);
}