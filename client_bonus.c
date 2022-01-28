/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:46:28 by rjada             #+#    #+#             */
/*   Updated: 2022/01/28 23:30:47 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	answer_handle(int sig_id)
{
	if (sig_id == SIGUSR2)
	{
		ft_putendl_fd(RECIEVED_SUCCESS, STDOUT);
		exit(EXIT_SUCCESS);
	}
}

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
			usleep(200);
		}
		++i;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	usr_action;
	
	if (argc != 3 || !is_valid_pid(argv[1]) || !ft_strlen(argv[2]))
		ft_error(ERR_MSG);
	ft_memset(&usr_action, 0, sizeof(usr_action));
	usr_action.sa_handler = answer_handle;
	sigaction(SIGUSR2, &usr_action, NULL);
	send_message(ft_atoi(argv[1]), argv[2]);
	ft_putnbr_fd(getpid(), STDOUT);
	ft_putendl_fd("", STDOUT);
	while (TRUE)
		pause();
	return (0);
}
