/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_sec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:33:07 by slasfar           #+#    #+#             */
/*   Updated: 2024/11/04 21:55:22 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_unsnbr(n / 10);
		i += ft_unsnbr(n % 10);
	}
	else
		i += ft_putchar (n + 48);
	return (i);
}

int	ft_puthex(unsigned int nb, char c)
{
	char	*table_l;
	char	*table_u;
	int		i;

	i = 0;
	table_u = "0123456789ABCDEF";
	table_l = "0123456789abcdef";
	if (nb >= 16)
		i += ft_puthex(nb / 16, c);
	if (c == 'x')
		i += ft_putchar(table_l[nb % 16]);
	else if (c == 'X')
		i += ft_putchar(table_u[nb % 16]);
	return (i);
}

int	ft_puthex_ptr(uintptr_t nb)
{
	char	*table ;
	int		i;

	table = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
		i += ft_puthex_ptr(nb / 16);
	i += ft_putchar(table[nb % 16]);
	return (i);
}
