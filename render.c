#include "ft_printf.h"
#include "libft/libft.h"

void	render_format(t_data *data)
{
	char specifier;

	specifier = data->format.specifier;
	if (specifier == 'c')
		print_char(data, va_arg(data->ap, int));
	else if (specifier == 's')
		print_str(data, va_arg(data->ap, char *));
	// else if (specifier == 'p')
	// 	print_ptr(data, va_arg(data->ap, void *));
	// else if (specifier == 'd')
	// 	print_int(data, va_arg(data->ap, int));
	// else if (specifier == 'i')
	// 	print_int(data, va_arg(data->ap, int));
	// else if (specifier == 'u')
	// 	print_int(data, va_arg(data->ap, int));
	// else if (specifier == 'x')
	// 	print_hexa(data, va_arg(data->ap, int));
	// else if (specifier == 'X')
	// 	print_hexa(data, va_arg(data->ap, int));
	// else if (specifier == '%')
	// 	print_char(data, '%');
}