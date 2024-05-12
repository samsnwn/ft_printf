#include "ft_printf.h"

void  write_buffer(t_data *data, char c)
{
  if (data->buffer_index == BUFFER_SIZE)
    flush_buffer(data);
  data->buffer[data->buffer_index++] = c;
}

void flush_buffer(t_data *data)
{
  data->written_chars += write(1, data->buffer, data->buffer_index);
  ft_memset(data->buffer, 0, BUFFER_SIZE);
  data->buffer_index = 0;
}

void  putchar_n(char c, int precision, t_data *data)
{
  if (precision <= 0)
    return;
  while (precision--)
    write_buffer(data, c);
}
