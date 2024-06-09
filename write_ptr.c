#include "ft_printf.h"

static int	count_hex(unsigned long n)
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
	char	*hex;
	char	*base;

	base = "0123456789abcdef";
	size = count_hex(n);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[n % 16];
		n = n / 16;
		size--;
	}
	return (hex);
}

int	write_ptr(void *ptr)
{
	int len;
	char *str;
	unsigned long n;

	n = (unsigned long)ptr;
	str = create_str(n);
	len = write_str(str);
	free(str);
	return (len);
}