#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void    sig_handler(int signum)
{
    if (signum == SIGUSR1)
        ft_putstr("SIGUSR1 USED \n");
    else if (signum == SIGUSR2)
        ft_putstr("SIGUSR2 USED \n");
}

int main(void)
{
    struct  sigaction   sa_signal;
    int                 error_check;

    ft_putstr("PID: ");
    ft_putnbr(getpid());
    ft_putchar('\n');
    sa_signal.sa_handler = sig_handler;
    error_check = sigaction(SIGUSR1, &sa_signal, NULL);
    error_check = sigaction(SIGUSR2, &sa_signal, NULL);
    if (error_check == -1)
		ft_putstr("ERROR\n");
    while (1)
        pause();
    return (0);
}