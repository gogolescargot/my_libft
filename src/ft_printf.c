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
