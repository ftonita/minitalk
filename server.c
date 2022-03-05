#include "minitalk.h"

int	print_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

void	signal_parse(int index, siginfo_t *info, void *u)
{
	static int	c;
	static int	i;

	(void)u;
	if (index == SIGUSR1)
		c += 1 << (7 - i);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			if (kill(info->si_pid, SIGUSR2))
				print_error("\nError: Failing signing");
		}
		ft_putchar_fd(c, 1);
		i = 0;
		c = '\0';
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	t;
	(void)argv;
	if (argc == 1)
	{
		ft_putstr_fd("Server PID:\t", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		t.sa_sigaction = signal_parse;
		if (sigaction(SIGUSR1, &t, 0) == -1 || \
			sigaction(SIGUSR2, &t, 0) == -1)
			print_error("\nError: Failed signing!");
		while (1)
			pause();
	}
	else
		print_error("\nError: Shouldn't be any args\n");
}