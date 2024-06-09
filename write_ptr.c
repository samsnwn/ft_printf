#include "ft_printf.h"

static int	nbr_size(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*create_str(unsigned long n)
{
	int		size;
	char	*str;
	char	*base;

	base = "0123456789abcdef";
	size = nbr_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = base[n % 16];
		n /= 16;
		size--;
	}
	return (str);
}

int	write_ptr(void *ptr)
{
	int written_chars;
	char *str;
	unsigned long n;

	n = (unsigned long)ptr;
	str = create_str(n);
	written_chars = write_str(str);
	free(str);
	return (written_chars);
}