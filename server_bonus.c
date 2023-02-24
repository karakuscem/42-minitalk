/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:00:55 by ckarakus          #+#    #+#             */
/*   Updated: 2023/02/24 21:11:51 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_convert_char(int data, pid_t *client_pid)
{
	static unsigned int		i = 7;
	static unsigned char	c;

	c += data << i;
	if (i == 0)
	{
		i = 7;
		write(1, &c, 1);
		c = 0;
	}
	else
		i--;
	if ((char)c == '\0')
	{
		kill(*client_pid, SIGUSR2);
		*client_pid = 0;
	}
}

void	ft_sig_handler(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		ft_convert_char(1, &client_pid);
	else if (sig == SIGUSR2)
		ft_convert_char(0, &client_pid);
}

int	main(void)
{
	int					pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_putstr_fd("PID => ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = ft_sig_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
