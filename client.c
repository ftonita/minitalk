#include "minitalk.h"

void	convers_dec(char c, int pid)
{
	int	i;
	int	b;

	b = 8;
	i = 0;
	while (i < b)
	{
		if ((c << i) & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				print_error("SIGUSR1 == -1\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				print_error("SIGUSR2 == -1\n");
		}
		i++;
		usleep(600);
	}
}

int	ascii_to_bin(char *string, int pid)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(string);
	while (i <= l)
	{
		convers_dec(string[i], pid);
		i++;
	}
	return (0);
}

void	signal_sent(int index, siginfo_t *info, void *u)
{
	(void)index;
	(void)info;
	(void)u;
	ft_putstr_fd("Signal was sent successfully\n", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	talk;

	talk.sa_sigaction = signal_sent;
	if ((sigaction(SIGUSR2, &talk, 0) == -1))
		print_error("\nFailed signing!\n");
	if (argc != 3)
		print_error("\nError: need 2 args\n");
	else
		ascii_to_bin(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
