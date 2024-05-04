#include "ft_printf.h"

// %[0-' '#+][10][.3]d

int	parse_format(t_data *data)
{
	// 0 - Refresh the data
	ft_memset(&data->format, 0, sizeof(t_format));
	// Set precision value to 0, not width
	data->format.precision = -1;

	// 1 - [0-' '#+]
	parse_flags(data);

	// 2  - [width *]
	// parse_width(data);
	get_value(data, &data->format.width);

	// 3 - [.precision *]
	if (*data->str == '.' && *(++data->str))
		// parse_precision(data);
		get_value(data, &data->format.precision);
}