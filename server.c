/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:00:55 by ckarakus          #+#    #+#             */
/*   Updated: 2023/02/22 00:13:33 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_convert_char(int data)
{
	static unsigned int		i = 7;
	static unsigned char	c;

	c += data << i;
	if (i == 0)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
	else
		i--;
}

void	ft_sig_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_convert_char(1);
	else if (sig == SIGUSR2)
		ft_convert_char(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("PID => ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1)
		pause();
	return (0);
}