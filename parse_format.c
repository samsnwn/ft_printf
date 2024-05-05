#include "ft_printf.h"

static void parse_flags(t_data *data);
static void parse_width_precision(t_data *data, int *value);
static void parse_specifiers(t_data *data);

// %[0-' '#+][10][.3]d
// Fills the struct with the flags found in the format string
int	parse_format(t_data *data)
{
	// 0 - Refresh the data
	ft_memset(&data->format, 0, sizeof(t_format));
	// I can set precision value to 0, not width
	data->format.precision = -1;

	// 1 - [0-' '#+] 
	parse_flags(data);

	// 2  - [width *]
	parse_width_precision(data, &data->format.width);
	// 3 - [.precision *]
	if (*data->str == '.' && *(++data->str))
		parse_width_precision(data, &data->format.precision);
	
	parse_specifiers(data);
	return 0;
}

static void parse_flags(t_data *data)
{
	while (ft_strchr(FLAGS, *data->str))
	{
		if (*data->str == '-')
			data->format.left_padding = 1;
		else if (*data->str == '0')
			data->format.zero = 1;
		else if (*data->str == '#')
			data->format.hash = 1;
		else if (*data->str == ' ')
			data->format.space = 1;
		else if (*data->str == '+')
			data->format.sign = 1;
		++data->str;
	}
}

static void parse_width_precision(t_data *data, int *value)
{
	// If * is found
	if (*data->str == '*')
	{
		// the value will be its corresponding argument in arg list
		*value = va_arg(data->ap, int);
		++data->str;
		return; 
	}

// if not found we convert the string to a number
	*value = ft_atoi(data->str);
}

static void parse_specifiers(t_data *data)
{
	// 4 - Specifiers
	if (!ft_strchr(SPECIFIERS, *data->str))
		return ;
	else
	{
		data->format.specifier = *data->str;

		// BASES CHECK
		if (ft_strchr("diu", data->format.specifier))
			data->format.base = 10;
		else if (ft_strchr("xXp", data->format.specifier))
		{
			data->format.base = 16;
			if (data->format.specifier == 'X')
				data->format.uppercase = 1;
		}
	}
}