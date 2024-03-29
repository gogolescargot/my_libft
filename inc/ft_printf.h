/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:31:29 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/20 21:42:29 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);

size_t	ft_strlen(const char *s);
void	percent(const char *s, int *l, va_list argptr);

void	put_char(char c, int *l);
void	put_str(char *s, int *l);
void	put_ptr(void *p, int *l);
void	put_nbr(long nbr, int base, int uppercase, int *l);

#endif