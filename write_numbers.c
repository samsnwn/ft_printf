#include "ft_printf.h"

int	write_digit(long int n)
{
	int	written_chars;

	written_chars = 0;
	if (n < 0)
	{
		if (n == -2147483647)
		{
			write(1, "-", 1);
			write(1, "2", 1);
			n = 147483647;
			return (write_digit(-n) + 2);
		}
		else
		{
			write(1, "-", 1);
			return (write_digit(-n) + 1);
		}
	}
	else if (n >= 10)
	{
		written_chars = write_digit(n / 10);
		return (written_chars + write_digit(n % 10));
	}
	else
	{
		return (written_chars + write_char(n + '0'));
	}
}

int	write_unsigned(unsigned int n, unsigned int base, int is_upper)
{
	int		written_chars;
	char	*hex_symbols;
	char	*upper_hex_symbols;

	hex_symbols = "0123456789abcdef";
	upper_hex_symbols = "0123456789ABCDEF";
	if (n < base)
	{
		if (is_upper == 0)
			return (write_char(hex_symbols[n]));
		else
			return (write_char(upper_hex_symbols[n]));
	}
	else
	{
		written_chars = write_unsigned(n / base, base, is_upper);
		return (written_chars + write_unsigned(n % base, base, is_upper));
	}
}