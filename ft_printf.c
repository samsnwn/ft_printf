/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:15:50 by samcasti          #+#    #+#             */
/*   Updated: 2024/04/30 16:15:52 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_args(const char *str);
static int init_data(t_data *data, const char *str);

int	ft_printf(const char *format, ...)
{
	t_data data;

	// 0 - Initialize data and start variadic machinery
	va_start(data.ap, format);
	if (init_data(&data, format) == -1)
		return (-1);
	
	while (*data.str)
	{
		// 1 - If stumbled into % parse the flags.
		if (*data.str == '%' && *(++data.str))
		{
			if (parse_format(&data))
			{
				return -1;
			} 
			render_format(&data);
		}
		// 2- 
		else
		{
			// stock char in 4k buffer
			write_buffer(&data, *data.str);
		}
		++data.str;

	}
	// write output
	flush_buffer(&data);
	// clean up functions
	va_end(data.ap);
	free(data.buffer);

	// return written chars
	return data.written_chars;

}

static int init_data(t_data *data, const char *str)
{
	data->str = str;
	data->written_chars = 0;
	data->buffer = malloc(BUFFER_SIZE);
	if (!data->buffer)
		return (-1);
	data->buffer_index = 0;
	ft_memset(data->buffer, 0, BUFFER_SIZE);
	return (0);
}

int	count_args(const char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}
