/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:45:24 by aalmela-          #+#    #+#             */
/*   Updated: 2022/03/15 14:53:15 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/client.h"

int	main(int argc, char *args[])
{
	pid_t				pid;
	char				*s;

	if (argc >= 3)
	{	
		if (validate_params(args[1]) > 0)
		{
			pid = (pid_t)ft_atoi(args[1]);
			s = args[2];
			while (*s != 0)
			{
				send_char(pid, *s);
				s++;
			}
			send_char(pid, '\n');
		}
		else
			ft_putstr_fd("PID is invalid\n", 1);
	}
	else
		return (-1);
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
