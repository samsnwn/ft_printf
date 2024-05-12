#include "ft_printf.h"
#include "libft/libft.h"

void  print_char(t_data *data, char c)
{
  int width;

  width = data->format.width;
  // If wifth = 1, do nothing
  if (width > 1)
  {
    if (data->format.left_padding)
    {
      put_char_n((char)c, width);
    }
    else 
    {

    }
  }
}

void  print_str(t_data *data, char *str);
void  print_ptr(t_data *data, void *ptr);
void  print_int(t_data *data, int a);
void  print_hexa(t_data *data, int a);