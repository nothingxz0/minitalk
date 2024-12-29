/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:05:07 by slasfar           #+#    #+#             */
/*   Updated: 2024/11/09 00:06:52 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		counter;
	int		i;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX\%", str[i + 1]))
		{
			counter += ft_ifs(str[++i], args);
			i++;
		}
		else
			counter += ft_putchar(str[i++]);
	}
	va_end(args);
	return (counter);
}
