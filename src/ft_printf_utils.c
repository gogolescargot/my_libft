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

#include "ft_printf.h"

void	put_char(char c, int *l)
{
	*l += write(1, &c, 1);
}

void	put_str(char *s, int *l)
{
	if (!s)
		*l += write(1, "(null)", 6);
	else
		*l += write(1, s, ft_strlen(s));
}

void	put_nbr(long nbr, int base, int uppercase, int *l)
{
	char	*table;

	table = "0123456789abcdef0123456789ABCDEF";
	if (nbr == -2147483648)
	{
		put_str("-2147483648", l);
		return ;
	}
	if (nbr < 0)
	{
		put_char('-', l);
		nbr *= -1;
	}
	if (nbr >= base)
		put_nbr(nbr / base, base, uppercase, l);
	put_char(table[nbr % base + uppercase], l);
}

void	putptr_rec(size_t p, int *l, char *base)
{
	if (p >= 16)
		putptr_rec(p / 16, l, base);
	put_char(base[p % 16], l);
}

void	put_ptr(void *p, int *l)
{
	char	*base;

	base = "0123456789abcdef";
	if (p == NULL)
	{
		put_str("(nil)", l);
		return ;
	}
	else
	{
		put_str("0x", l);
		putptr_rec((size_t)p, l, base);
	}
}
