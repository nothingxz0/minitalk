/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:32:40 by slasfar           #+#    #+#             */
/*   Updated: 2024/12/25 14:42:45 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include	"ft_printf/ft_printf.h"

void	get_bits(int sig, siginfo_t *info, void *context)
{
	static char	tmp;
	static int	i;

	tmp |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", tmp);
		if (tmp == '\0')
			ft_printf("\n\n");
		tmp = 0;
		i = 0;
	}
	else
		tmp <<= 1;
	usleep(50);
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &get_bits;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("SERVER PID ----------> %d\n", getpid());
	while (1)
		pause();
}
