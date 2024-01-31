/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:33:10 by ggalon            #+#    #+#             */
/*   Updated: 2024/01/31 01:33:10 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	percent(const char *s, int *l, va_list argptr)
{
	if (s[1] == 'c')
		put_char(va_arg(argptr, int), l);
	else if (s[1] == 's')
		put_str(va_arg(argptr, char *), l);
	else if (s[1] == 'p')
		put_ptr(va_arg(argptr, void *), l);
	else if (s[1] == 'd' || s[1] == 'i')
		put_nbr(va_arg(argptr, int), 10, 0, l);
	else if (s[1] == 'u')
		put_nbr(va_arg(argptr, unsigned int), 10, 0, l);
	else if (s[1] == 'x')
		put_nbr(va_arg(argptr, unsigned int), 16, 0, l);
	else if (s[1] == 'X')
		put_nbr(va_arg(argptr, unsigned int), 16, 16, l);
	else if (s[1] == '%')
		put_char('%', l);
	else
		*l += write(1, s, 2);
}
