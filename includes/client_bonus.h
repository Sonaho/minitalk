/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:36:41 by aalmela-          #+#    #+#             */
/*   Updated: 2022/03/15 14:52:27 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"

struct s_args
{
	pid_t	pid;
	char	*s;
};

void	send_char(pid_t pid, char c);
int		validate_params(char *pid);
void	listener_client(int signum, siginfo_t *info);
void	signal_event(struct sigaction sa);
#endif
