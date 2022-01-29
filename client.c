/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:46:28 by rjada             #+#    #+#             */
/*   Updated: 2022/01/29 15:01:57 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_valid_pid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static void	send_message(int pid, char *message)
{
	int		i;
	int		bit;

	i = 0;
	while (message[i])
	{
		bit = 8;
		while (bit--)
		{
			if (message[i] >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
		++i;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !is_valid_pid(argv[1]) || !ft_strlen(argv[2]))
		ft_error(ERR_MSG);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
