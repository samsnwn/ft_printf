#include "ft_printf.h"
#include "libft/libft.h"

void	print_char(t_data *data, char c)
{
	int	width;

	width = data->format.width;
	if (width > 1)
	{
		if (data->format.left_padding)
		{
			putchar_n(c, 1, data);
			putchar_n(' ', width - 1, data);
		}
		else
		{
			putchar_n(' ', width - 1, data);
			putchar_n(c, 1, data);
		}
	}
	putchar_n(c, 1, data);
}

void	print_str(t_data *data, char *str)
{
	if (str == NULL)
		str = "(null)";
	set_spaces(data, str);
	if (data->format.left_padding)
	{
		if (data->format.precision >= 0)
			putstr_n(str, data->format.precision, data);
		else
			putstr_n(str, ft_strlen(str), data);
		putchar_n(' ', data->format.padding_spaces, data);
	}
	else
	{
		putchar_n(' ', data->format.padding_spaces, data);
		if (data->format.precision >= 0)
			putstr_n(str, data->format.precision, data);
		else
			putstr_n(str, ft_strlen(str), data);
	}
}


// void  print_ptr(t_data *data, void *ptr)
// {

// }
// void  print_int(t_data *data, int a)
// {

// }
// void  print_hexa(t_data *data, int a)
// {

// }