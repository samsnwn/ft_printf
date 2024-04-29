int	count_args(const char *str);

int	ft_printf(const char *, ...)
{
	// loop over char* until we find a%,then we stop and say: this will be one argument.
	// count_args(const char *);
	return (0);
}

int	count_args(const char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}