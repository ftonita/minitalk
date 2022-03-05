#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(long long n, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_is_space(int c);

#endif