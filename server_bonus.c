/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:47:35 by rjada             #+#    #+#             */
/*   Updated: 2022/01/28 23:29:15 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	recieve_handle(int sig_id, siginfo_t *info, void *context)
{
	static unsigned char	chr;
	static int				bit;
	(void) context;
	
	if (sig_id == SIGUSR2)
		chr |= (1 << (7 - bit));
	++bit;
	if (bit == 8)
	{
		bit = 0;
		if (chr)
			ft_putchar_fd(chr, STDOUT);
		else
		{		
			kill(info->si_pid, SIGUSR2);
			ft_putendl_fd("", STDOUT);
		}
		chr = 0;
	}
}

int	main(int argc, char **argv)
{
	(void) argv;
	struct sigaction	usr_action;

	if (argc > 1)
		ft_error(ERR_MSG);
	ft_memset(&usr_action, 0, sizeof(usr_action));
	usr_action.sa_sigaction = recieve_handle;
	usr_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &usr_action, NULL);
	sigaction(SIGUSR2, &usr_action, NULL);
	ft_putstr_fd("Server PID: ", STDOUT);
	ft_putnbr_fd(getpid(), STDOUT);
	ft_putendl_fd("", STDOUT);
	while (TRUE)
		pause();
	return (0);
}
