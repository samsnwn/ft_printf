#include "ft_printf.h"

static void parse_flags(t_data *data);
static void parse_width_precision(t_data *data, int *value);
static void parse_specifiers(t_data *data);

int	parse_format(t_data *data)
{
	ft_memset(&data->format, 0, sizeof(t_format));
	parse_flags(data);
	parse_width_precision(data, &data->format.width);
	if (*data->str == '.' && *(++data->str))
		parse_width_precision(data, &data->format.precision);
	parse_specifiers(data);
	return 0;
}

// Fills the struct with the flags found in the format string
static void parse_flags(t_data *data)
{
	while (ft_strchr(FLAGS, *data->str))
	{
		if (*data->str == '-')
			data->format.left_padding = TRUE;
		else if (*data->str == '0')
			data->format.zero = TRUE;
		else if (*data->str == '#')
			data->format.hash = TRUE;
		else if (*data->str == ' ')
			data->format.space = TRUE;
		else if (*data->str == '+')
			data->format.sign = TRUE;
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
				data->format.uppercase = TRUE;
		}
	}
}