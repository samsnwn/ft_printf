#include "ft_printf.h"
#include "libft/libft.h"

void	set_spaces(t_data *data, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (data->format.width > 0)
	{
		if (data->format.precision >= 0)
		{
			if (data->format.precision > len)
			{
				data->format.padding_spaces = data->format.width - len;
			}
			else if (data->format.precision < len)
			{
				data->format.padding_spaces = data->format.width
					- data->format.precision;
			}
		}
		else
		{
			data->format.padding_spaces = data->format.width - len;
		}
	}
}