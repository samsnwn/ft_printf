#include "ft_printf.h"

int	write_char(int c)
{
	return (write(1, &c, 1));
}

int	write_str(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}