/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:27:42 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/27 18:48:11 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_printf.h"
# include "libft/includes/libft.h"

int		ft_printf(const char *format, ...);
size_t	count(int n);
char	*add(char *a, char b);
char	*inta(va_list ap, char *str);
void	percent(const char *format, char **str, va_list ap);
char	*ch(va_list ap, char *str);
char	*ar(va_list ap, char *str);
#endif
