/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:15:57 by samcasti          #+#    #+#             */
/*   Updated: 2024/04/30 16:15:59 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE (4096)
# define FLAGS "-0# +"
# define SPECIFIERS "cspdiuxX%"
# define TRUE 1
# define FALSE 0

// 1 - Copy string into a 4k buffer until % is found
// 2 - Parse the flags: When % is found, check which flags and store the variable in a struct ex: t_format.left_padding = 1;
// 3 - After the flags are parsed, we look at the arg list and render each argument according to the flag struct in its corresponding position 

//   FLAGS    WIDTH		PRECISION    SPECIFIER
// [0-' '#+][width *][.precision *][specifier]
typedef struct s_format
{
	// Flags
	int			left_padding;
	int			sign;
	int			space;
	int			zero;
	int			hash;

	int			width;
	int			precision;
 	// cspdiuxX%
	char		specifier;
 // base
	int 		base;
	int			uppercase;

}				t_format;


// Box to pass by reference to functions
typedef struct s_data
{
	// Pointer copy to format string
	const char *str;
	// Argument pointer va_list ->va_arg(ap, int)
	va_list		ap;
	// Number of chars written
	int			written_chars;
	// Pointer to Buffer to store the string in the HEAP
	char		*buffer;
	// Index to write in the buffer
	int			buffer_index;

	// Format struct
	t_format	format;
}				t_data;

int	ft_printf(const char *format, ...);
int	parse_format(t_data *data);
void  write_buffer(t_data *data, char c);
void flush_buffer(t_data *data);
void  print_char(t_data *data, char c);
void  putchar_n(char c, int precision, t_data *data);
// void  print_ptr(t_data *data, void *ptr);
// void  print_int(t_data *data, int a);
// void  print_hexa(t_data *data, int a);
void putstr_n(char *str, int precision, t_data *data);

#endif
