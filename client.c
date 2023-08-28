/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:39:45 by asajid            #+#    #+#             */
/*   Updated: 2023/06/07 12:35:36 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *str)
{
	int	bit;
	int	i;

	bit = 7;
	i = 0;
	while (str[i])
	{
		while (bit >= 0)
		{
			if (str[i] & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
			bit--;
		}
		i++;
		bit = 7;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("INVALID NO:OF ARGUMENTS\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 0)
	{
		ft_putstr("INVALID PID\n");
		return (1);
	}
	send_message(pid, av[2]);
	send_message(pid, "\n");
}
