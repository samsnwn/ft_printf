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