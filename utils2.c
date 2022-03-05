int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\f' || \
	c == '\r' || c == '\n' || c == '\v');
}

int	ft_atoi(const char *str)
{
	int	x;
	int	minus;

	x = 0;
	minus = -1;
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			minus = 1;
	while (*str && ft_isdigit(*str))
		x = x * 10 - (*str++ - '0');
	return (x * minus);
}