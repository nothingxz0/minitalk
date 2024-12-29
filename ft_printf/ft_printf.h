/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:39:29 by slasfar           #+#    #+#             */
/*   Updated: 2024/11/04 20:19:24 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_ifs(char c, va_list args);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_unsnbr(unsigned int n);
int		ft_puthex(unsigned int nb, char c);
char	*ft_strchr(const char *s, int c);
int		ft_puthex_ptr(uintptr_t nb);

#endif
