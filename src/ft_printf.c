/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:55:06 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/21 06:26:14 by ggalon           ###   ########.fr       */
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

int	ft_printf(const char *s, ...)
{
	int		l;
	size_t	i;
	va_list	argptr;

	i = -1;
	l = 0;
	if (!s)
		return (-1);
	va_start(argptr, s);
	while (++i < ft_strlen(s))
	{
		if (s[i] == '%')
		{
			if (!s[i + 1])
				return (va_end(argptr), -1);
			percent(s + i, &l, argptr);
			i++;
		}
		else
			put_char(s[i], &l);
	}
	va_end(argptr);
	return (l);
}
