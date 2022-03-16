/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:45:24 by aalmela-          #+#    #+#             */
/*   Updated: 2022/03/16 10:14:08 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/client_bonus.h"

int	main(int argc, char *args[])
{
	char				*s;
	struct sigaction	sa;

	if (argc >= 3)
	{	
		if (validate_params(args[1]) > 0)
		{
			s = args[2];
			ft_memset(&sa, 0, sizeof(sa));
			signal_event(sa);
			while (*s != 0)
			{
				send_char((pid_t)ft_atoi(args[1]), *s);
				s++;
			}
			send_char((pid_t)ft_atoi(args[1]), '\n');
			ft_putstr_fd("\nEnd transmision\n", 1);
		}
		else
			ft_putstr_fd("PID is invalid\n", 1);
	}
	else
		ft_putstr_fd("Invalid parameters\n", 1);
	return (0);
}

void	send_char(pid_t pid, char c)
{
	int	c_b;

	c_b = 0;
	while (c_b < 8)
	{
		if (c & (1 << c_b))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c_b ++;
		pause ();
		usleep(100);
	}
}

int	validate_params(char *pid)
{
	int				i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]))
			return (-1);
		i ++;
	}
	return (i);
}

void	signal_event(struct sigaction sa)
{
	ft_putstr_fd("PID:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_handler = (void *)listener_client;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL))
		return ;
}

void	listener_client(int signum, siginfo_t *info)
{
	static int	i = 0;

	if (signum != SIGUSR1)
		return ;
	if (i != info->si_pid)
	{
		i = info->si_pid;
		ft_putstr_fd("Sending message to server PID:", 1);
		ft_putnbr_fd(i, 1);
	}
}
