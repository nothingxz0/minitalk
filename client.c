/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:57:06 by slasfar           #+#    #+#             */
/*   Updated: 2024/12/25 14:34:20 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

volatile sig_atomic_t	g_flag = 0;

void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
}

int	pid_check(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_printf("INVALID PID!");
			exit(1);
		}
		res = res * 10 + (str[i++] - 48);
	}
	return (res);
}

void	send_bits(int pid, char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
			usleep(50);
		g_flag = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	signal(SIGUSR1, handle_sig);
	if (ac != 3)
	{
		ft_printf ("Usage: ./client <pid> <message>");
		exit(1);
	}
	pid = pid_check(av[1]);
	i = 0;
	while (av[2][i])
		send_bits(pid, av[2][i++]);
	usleep(50);
	send_bits(pid, '\0');
}
