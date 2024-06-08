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
# include <stdio.h>

int	ft_printf(const char *format, ...);
int print_args(va_list ap, char specifier);
int	write_char(int c);
int	write_str(char *str);
int write_digit(long int n);
int	write_unsigned(unsigned int n, unsigned int base, int is_upper);
int	write_ptr(void *ptr);
size_t	ft_strlen(const char *s);

#endif
