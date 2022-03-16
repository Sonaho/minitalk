/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:36:41 by aalmela-          #+#    #+#             */
/*   Updated: 2022/03/15 15:11:46 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"

struct s_byte
{
	char	current_char;
	int		current_bit;
};

void	minitalk_server(int signum, siginfo_t *info);
void	show_pid(void);
void	show_client(int pid);
#endif
