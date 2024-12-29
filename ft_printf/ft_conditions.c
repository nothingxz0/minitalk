/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:06:54 by slasfar           #+#    #+#             */
/*   Updated: 2024/11/06 23:09:23 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ifs(char c, va_list args)
{
	int			counter;
	uintptr_t	nb;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		counter += ft_unsnbr(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		nb = (uintptr_t)va_arg(args, void *);
		if (nb == 0)
			return (counter += ft_putstr("(nil)"));
		ft_putstr("0x");
		counter += (2 + ft_puthex_ptr(nb));
	}
	else if (c == 'x' || c == 'X')
		counter += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		counter += ft_putchar('%');
	return (counter);
}
