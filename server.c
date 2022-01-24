/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:47:35 by rjada             #+#    #+#             */
/*   Updated: 2022/01/24 20:59:00 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	(void) argv;

	if (argc > 1)
		ft_error("Error");
	ft_putnbr_fd(getpid(), STDOUT);
	ft_putendl_fd("", STDOUT);
	while (TRUE)
		pause();
	return (0);
}
