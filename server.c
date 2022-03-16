/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:52:48 by aalmela-          #+#    #+#             */
/*   Updated: 2022/03/15 12:36:22 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/server.h"

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = (void *)minitalk_server;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		return (1);
	show_pid();
	while (1)
		sleep (5);
	exit(1);
	return (0);
}

void	minitalk_server(int signum)
{
	static struct s_byte	sb = {0, 0};

	if (signum == SIGUSR2)
		sb.current_char |= 1 << sb.current_bit;
	sb.current_bit ++;
	if (sb.current_bit == 8)
	{
		ft_putchar_fd(sb.current_char, 1);
		sb.current_char = 0;
		sb.current_bit = 0;
	}
}

void	show_pid(void)
{
	ft_putstr_fd("PID ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}
